//	/adm/daemons/channeld.c 
// Modified by Find.

#pragma optimize

//#define CGI_MUDCHAT	"/WWW/cgi-bin/mudchat"
#define EXCLUDE_VERB	({"sys","wiz","gwiz","menpai"})

#define TIME_DISTANCE	15
#define CHAT_NUM	10
/* 15 秒钟之内说话超过 10 句,关频道 */

#include <ansi.h>
#include <net/dns.h>
#include <net/daemons.h>

inherit F_DBASE;

private int rnt = 60;
private string replace_msg(string msg);
private string seek_break(string ll);

#include "badword.c"

mapping channels = ([
	"guanfu":  ([   "msg_speak": HIR "【官府通告】：%s\n"NOR,
			"no_user": 1	/* 纯粹广播用频道，非玩家（包括巫师）使用
					   用于发布通缉令、官府动向等信息. by Find.*/
			]),

	"paimai":  ([   "msg_speak": HIY "【拍卖大会】：%s\n"NOR,
			"no_user": 1	/* 纯粹广播用频道，非玩家（包括巫师）使用
					   用于当铺定期举行的拍卖大会. by Find.*/
			]),

	"business":	([   "msg_speak": HIG "【商界传闻】：%s\n"NOR,
			"no_user": 1	/* 纯粹广播用频道，非玩家（包括巫师）使用,
					   商界消息的发布. by Find.*/
			]),

        "sys":  ([      "msg_speak": HIR "【系统】%s：%s\n" NOR,
			"wiz_only": 1 ]),

        "wiz":  ([      "msg_speak": HIY "【管理员】%s：%s\n" NOR,
			"msg_emote": HIY "【管理员】%s\n" NOR,
			"wiz_only": 1
                        ]),

	"gwiz":	([	"msg_speak": WHT "〖网际巫师〗%s%s\n" NOR,
			"msg_emote": WHT "〖网际巫师〗%s\n" NOR,
			"wiz_only": 1,
			"intermud": GCHANNEL,
			"channel": "gwiz",
			"filter": 1
			]),

        "tx":   ([      "msg_speak": HIG "〖天下论谈〗%s：%s\n" NOR,
                        "msg_emote": HIG "〖天下论谈〗%s\n" NOR,
                        "intermud": GCHANNEL,
                        "channel": "tx",
                        "filter": 1,
                         ]),

        "chat": ([      "msg_speak": HIC "【闲聊】%s：%s\n" NOR,
			"msg_emote": HIC "【闲聊】%s\n" NOR,
                         ]),

        "rumor":([      "msg_speak": HIM "【谣言】%s：%s\n" NOR,
			"msg_emote": HIM "【谣言】%s\n" NOR,
			"anonymous": "某人"
                        ]),

//added by Find.
	"menpai":([     "msg_speak": HIW "【name_of_menpai】%s：%s\n" NOR,
			"msg_emote": HIW "【name_of_menpai】%s\n" NOR
			]),
// end.
]);

int block_rumor = 0;
int block_chat = 0;
int block_tx =0;

void create()
{
        seteuid(getuid());      // This is required to pass intermud access check.
        set("channel_id", "频道精灵");
}

varargs int do_channel(object me, string verb, string arg, int emote)
{
	object *ob;
        string *tuned_ch, who,oldarg,oldverb;
        string  vb2;
	// added by by Find.
	string remote_user,mud,word,startxx;
	string inter_arg;
	int time,count,last_chat,n;
	// end.

	if(me->is_busy() && !wizardp(me))
		return notify_fail(BUSY_MESSAGE);

	if(!stringp(verb) || (verb == ""))
		return 0;

        if( verb[<1] == '*' )
	{
                emote = 1;
                verb = verb[0..<2];
        }

	else if( verb[<1] == '#' )
	{
                emote = 2;
                verb = verb[0..<2];
                vb2=arg; 
        }

	if(emote && (verb == ""))
		verb = "chat";

	else if(verb[0] == '*' && sizeof(verb) > 1)
	{
		if(arg && stringp(arg))
			arg = sprintf("%s %s",verb[1..],arg);
		else
			arg = verb[1..];
		verb = "chat";
		emote = 1;
	}

        else if( !mapp(channels) || undefinedp(channels[verb]) )
                return 0;

	if(userp(me))
	{
		/* 保护年龄不能造谣，不能使用网际频道 */
		if((me->query("age") <= PROTECT_AGE)
		&& (verb == "tx"
		|| verb == "rumor")
		&& !wizardp(me))
			return notify_fail("你现在还不能使用这个频道。\n");

		if(me->is_ghost() && !wizardp(me))
			return notify_fail(CYN "你张了张嘴，可是什么也没说出来......\n" NOR);

		time=time();
		if(me->query("channel/chat_block")
		&& (time-me->query("channel/chat_block"))<0 )
			return notify_fail("你的交谈频道被暂时关闭了。\n");

		if(me->query("chblk_on"))
			return notify_fail("你的交谈频道关闭了。\n");

		count=me->query("channel/chat_count");
		last_chat=me->query("channel/last_chat");

		if( time - last_chat > TIME_DISTANCE )
		{
			me->set("channel/last_chat",time);
			me->set("channel/chat_count",0);
		}
		else
		{
			count++;
			if( count >= CHAT_NUM && !wizardp(me) )
			{
				me->set("channel/chat_block",time+180);
					return notify_fail("因为短时间内讲话太多，你的交谈频道被暂时关闭了。\n");
			}
			me->set("channel/chat_count",count);
		}

		if((int)me->query("chblk_on") && !wizardp(me))
		{
			me->set("chblk_rumor", 1);
        	        me->set("chblk_chat", 1);
			me->set("chblk_tx",1);
			me->set("chblk_menpai",1);
	        }

	        if(!(int)me->query("chblk_on") )
        	{
	                me->set("chblk_rumor", 0);
        	        me->set("chblk_chat", 0);
			me->set("chblk_tx",0);
			me->set("chblk_menpai",0);
	        }
	}

	if(!me->query("family/family_name") && ( verb == "menpai" || verb == "menpai*" || verb == "menpai#"))
		return notify_fail(YEL "你目前没有加入任何组织！\n" NOR);

	if(me->query("chblk_menpai") && ( verb == "menpai" || verb == "menpai*" || verb == "menpai#"))
		return notify_fail(RED "ｏｏｐｓ！你的门派频道被关闭了！\n" NOR);
        if ((int)me->query("chblk_rumor") && (verb == "rumor"||verb == "rumor*"||verb == "rumor#") )
		return notify_fail(RED"ｏｏｐｓ！你的谣言频道被关闭了！\n"NOR);
	if((int)me->query("chblk_tx") && (verb == "tx"||verb == "tx*"||verb == "tx#") )
                return notify_fail(RED"ｏｏｐｓ！你的天下论谈频道被关闭了！\n"NOR);
        if ((int)me->query("chblk_chat") && (verb == "chat"||verb == "chat*"||verb == "chat#") )
		return notify_fail(RED"ｏｏｐｓ！你的聊天频道被关闭了！\n"NOR);

	if ((int)block_rumor && (verb == "rumor"||verb == "rumor*"||verb == "rumor#") )
		return notify_fail(RED"遥言频道被关闭了！\n"NOR);
	if ((int)block_chat && (verb == "chat"||verb == "chat*"||verb == "rumor#") )
		return notify_fail(RED"聊天频道被关闭了！\n"NOR);
	if ((int)block_tx && (verb == "tx"||verb == "tx*"||verb == "tx#") )
		return notify_fail(RED"天下论谈频道被关闭了！\n"NOR);

	channels["chat"] = ([
		"msg_speak": HIC "【"+NATURE_D->season_chat()+"】%s：%s\n" NOR,
		"msg_emote": HIC "【"+NATURE_D->season_chat()+"】%s\n" NOR,
	]);

         channels["menpai"] = ([
		"msg_speak": HIW "【"+me->query("family/family_name")+"】%s：%s\n" NOR,
		"pai" : me->query("family/family_name"),
		"msg_emote": HIW "【" + me->query("family/family_name") + "】%s\n" NOR
	]);

        if(!stringp(arg) || arg == "" || arg == " ")
		arg = "...";

        if( userp(me) )
	{
		if(channels[verb]["wiz_only"] && !wizardp(me) )
			return 0;
		if(channels[verb]["no_user"])	// 纯广播用频道。
			return 0;

		if( (strlen(arg) > 640) && !wizardp(me) )
			return notify_fail("发布内容长度不要超过 320 个汉字。\n");
		
		// add by dicky

		for (n=0;n<sizeof(banned_word);n++){
		word = banned_word[n];
		startxx= "/d/wiz/prison";
		if( strsrch(arg,word) != -1){
		if (!me->query("badword") || me->query("badword") < 2){
		me->set("channel/chat_block",time+300);
                me->set("channel/tx_block",time+300);
                me->set("channel/rumor_block",time+300);
		message("channel:chat",
                        HIR"【系统通告】：使用者"+ me->query("name")+"言语中带有污秽言词，暂时关闭其所有公开聊天频道，并记录在案！\n"NOR,users());
		me->add("badword",1);
		}
		else{
		message("channel:chat",
                        HIR"【系统通告】：使用者"+ me->query("name")+"连续三次言语中带有污秽言词，被暂时监禁,并记录在案,等候处理!\n"NOR,users());
		me->delete("badword");
		me->move("/d/wiz/prison");
		me->set("startroom",startxx);
		}
		}
		}

		if(!undefinedp(channels[verb]["intermud"])
		&& !find_object(DNS_MASTER))
			return notify_fail("网际精灵没有被载入，不能使用网际频道。\n");

                if( ((arg+verb)==(string)me->query_temp("last_channel_msg")) && !wizardp(me))
			return notify_fail(CYN"用交谈频道说话请不要重复相同的讯息。\n"NOR);
		oldarg=arg;oldverb=verb;

                // If we speaks something in this channel, then must tune it in.
                tuned_ch = me->query("channels");
                if( !pointerp(tuned_ch) )
                        me->set("channels", ({ verb }) );
                else if( member_array(verb, tuned_ch)==-1 )
                        me->set("channels", tuned_ch + ({ verb }) );

                if( (emote==1) && !channels[verb]["intermud_emote"])
		{
			string vb,emote_arg;

                        if( sscanf(arg, "%s %s", vb, emote_arg)!= 2 )
			{
                                vb = arg;
                                emote_arg = "";
                        }

			if( sscanf(emote_arg,"%s@%s",remote_user,mud) == 2
			&& !undefinedp(channels[verb]["intermud"]) )
			{
				return GEMOTE_Q->send_msg(me,vb,remote_user,mud,verb);
			}

                        arg = EMOTE_D->do_emote(me, vb, emote_arg, emote,channels[verb]["anonymous"],
				verb,0 );
			if(!undefinedp(channels[verb]["intermud"]))
			inter_arg =  EMOTE_D->do_emote(me, vb, emote_arg, emote,channels[verb]["anonymous"],
				verb,1 );

                        if( !arg || (arg =="")) return 0;
                }
        }

        if( channels[verb]["anonymous"] )
	{
		who = channels[verb]["anonymous"];
                if (userp(me))
		{
			if(me->query("sen")<25)
				return notify_fail("说谣传命都不要了吗？\n");
			if(!wizardp(me))
				me->add("sen",-20);
			do_channel( this_object(), "sys", sprintf("谣言：%s(%s)。", me->name(1),
				me->query("id")));
                }
        }

        else if( userp(me) || !stringp(who = me->query("channel_id")) )
                who = me->name(1) + "(" + capitalize(me->query("id")) + ")";

        // Ok, now send the message to those people listening us.
        ob = filter_array( users(), "filter_listener", this_object(), channels[verb] );
        if( !arg || arg == "" || arg == " " ) arg = "...";

        if( emote==1 )
	{
		if (!stringp(arg))
			return notify_fail(CYN"没有定义这个动作.:)\n"NOR);
		message( "channel:" + verb,sprintf( channels[verb]["msg_emote"],(strlen(arg)>rnt)?replace_msg(arg):arg),ob );
		//if(member_array(verb,EXCLUDE_VERB) == -1)
		//CGI_MUDCHAT->add_chat(sprintf( channels[verb]["msg_emote"],arg));
        }

	else if ( emote == 2 )
	{
		if( !vb2 || vb2 == "" || vb2 == " " ) vb2 = "...";
		if(verb=="rumor")
			vb2=channels["rumor"]["anonymous"]+vb2+"\n";
		if(verb=="chat")
			vb2=me->name(1)+vb2+"\n";
		if(verb=="tx")
			vb2=me->name(1)+vb2+"\n";
		if(verb=="menpai")
			vb2=me->name(1)+vb2+"\n";

		message ("channel:"+verb, sprintf( channels[verb]["msg_emote"], (strlen(vb2)>rnt)?replace_msg(vb2):vb2 ),ob );
		//if(member_array(verb,EXCLUDE_VERB) == -1)
		//CGI_MUDCHAT->add_chat(sprintf( channels[verb]["msg_emote"], vb2 ));
	}

	else if(channels[verb]["no_user"])
	{
		message( "channel:" + verb,sprintf( channels[verb]["msg_speak"],
			/*(strlen(arg)>rnt)?replace_msg(arg):*/arg ),ob );
		//CGI_MUDCHAT->add_chat(sprintf( channels[verb]["msg_speak"],arg ));
	}

	else
	{
		if(verb == "rumor" && me == find_object(COMBAT_D))
			message( "channel:" + verb,sprintf( BWHT+channels[verb]["msg_speak"], who, (strlen(arg)>rnt)?replace_msg(arg):arg ), ob );
		else
			message( "channel:" + verb,sprintf( channels[verb]["msg_speak"], who, (strlen(arg)>rnt)?replace_msg(arg):arg ), ob );
		//if(member_array(verb,EXCLUDE_VERB) == -1)
		//CGI_MUDCHAT->add_chat(sprintf( channels[verb]["msg_speak"], who, arg ));
	}
         
	if( !undefinedp(channels[verb]["intermud"])
	&& base_name(me) != channels[verb]["intermud"]
	&& base_name(me) != GEMOTE_Q
	&& base_name(me) != GEMOTE_A )
		channels[verb]["intermud"]->send_msg(
			channels[verb]["channel"], me->query("id"), me->name(1),
				((emote==1)?inter_arg:arg),((emote==1)?1:0),
				channels[verb]["filter"] );

	if( userp(me) ) 
		me->set_temp("last_channel_msg", (oldarg+oldverb));

	if(!wizardp(me))
	{
		me->set_temp("justchat",1);
		call_out("del_justchat", 1, me);
        }

	if( arrayp(channels[verb]["extra_listener"]) )
	{
		channels[verb]["extra_listener"] -= ({ 0 });
		if( sizeof(channels[verb]["extra_listener"]) )
			channels[verb]["extra_listener"]->relay_channel(me, verb, arg);
	}

	if(userp(me) && !wizardp(me) && (verb == "rumor") && (emote != 1) && (random(10) < 2))
	message("channel:chat", sprintf(MAG BWHT"【"+NATURE_D->season_chat()+"】%s：%s传谣不慎，一不小心露出了破绽。\n" NOR,
		query("channel_id"), me->name(1)), ob);
	return 1;
}

private int filter_listener(object ppl, mapping ch)
{
	if( !environment(ppl) ) return 0;
        if( ch["wiz_only"] ) return wizardp(ppl);
	if( ch["no_user"] ) return 1;
	if( ch["pai"] )
	{
		if(ppl->query("family/family_name")
		&& (ppl->query("family/family_name") == ch["pai"]))
			return 1;
		// 巫师可以收听所有门派频道.
		if(wizardp(ppl))
			return 1;
		else return 0;
	}
        return 1;
}

void register_relay_channel(string channel)
{
	object ob;

	ob = previous_object();
	if( undefinedp(channels[channel]) || !ob) return;
	if( arrayp(channels[channel]["extra_listener"]) )
	{
		if( member_array(ob, channels[channel]["extra_listener"]) >=0 ) return;
		channels[channel]["extra_listener"] += ({ ob });
	}
	else
                channels[channel]["extra_listener"] = ({ ob });
}

int set_block(string channel, int d)
{
	if(!previous_object() || geteuid(previous_object()) != ROOT_UID)
		return 0;

	write("debug:  "+channel+" d="+sprintf("%d\n", d)); 
	if (channel == "rumor") block_rumor = d;
	if (channel == "chat") block_chat = d;
	if (channel == "tx") block_tx = d;

        return 1;
}

private void del_justchat(object me)
{
       if (objectp(me) &&  me->query_temp("justchat"))
               me->delete_temp("justchat");
}

// 自动折行 zmud 无法区分双字节文字如中文造成
// 乱码的情况
// Find.
private string replace_msg(string msg)
{
	string *bk;
	int i;

	if(!stringp(msg))
		return "";

	bk = explode(msg,"\n");

	for(i=0;i<sizeof(bk);i++)
	{
		if(strlen(bk[i]) > rnt)
			bk[i] = seek_break(bk[i]);
	}

	return implode(bk,"\n");
}

private string seek_break(string ll)
{
	int i,c;
	string head,end;

	if(!(ll[rnt-1]>>7))
	{
		head = ll[0..(rnt-1)];end = ll[rnt..];
		if(strlen(end) > rnt)
			end = seek_break(end);
		return sprintf("%s\n%s",head,end);
	}

	for(i=0;i<rnt;i++)
		if(!(ll[i]>>7))
			c++;

	if(c%2) {
		head = ll[0..rnt];end = ll[(rnt+1)..];
	} else {
		head = ll[0..(rnt-1)];end = ll[rnt..];
	}

	if(strlen(end) > rnt)
		end = seek_break(end);
	return sprintf("%s\n%s",head,end);
}
