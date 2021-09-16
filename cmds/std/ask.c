// ask.c
// modified by Find.

#include <ansi.h>

inherit F_CLEAN_UP;

string *msg_dunno = ({
	"$n摇摇头，说道：没听说过。\n",
	"$n睁大眼睛望着$N，显然不知道$P在说什么。\n",
	"$n耸了耸肩，很抱歉地说：无可奉告。\n",
	"$n说道：嗯....这我可不清楚，你最好问问别人吧。\n",
	"$n想了一会儿，说道：对不起，你问的事我实在没有印象。\n"
});

int main(object me, string arg)
{
	string dest, topic;
	object ob;
	mixed msg,retn;
	mapping inquirys;

	if(me->query("channel/chat_block")
	&& (time()-me->query("channel/chat_block"))<0 )
		return notify_fail("你的交谈频道被暂时关闭了。\n");

	seteuid(getuid());

	if( !arg
	|| ((sscanf(arg, "%s about %s", dest, topic) != 2)
	&& (sscanf(arg, "%s gy %s", dest, topic) != 2)) )
		return notify_fail("你要问谁什么事？\n");

	if( !objectp(ob = present(dest, environment(me))) )
		return notify_fail("这里没有这个人。\n");

	if( !ob->is_character() ) {
		message_vision("$N对着$n自言自语....\n", me, ob);
		return 1;
	}

	if( !ob->query("can_speak") )
	{
		message_vision("$N向$n打听有关『" + topic + "』的消息，但是$p显然听不懂人话。\n", me, ob);
		return 1;
	}

	if( !INQUIRY_D->parse_inquiry(me, ob, topic) )
		message_vision("$N向$n打听有关『" + topic + "』的消息。\n", me, ob);

	if( !living(ob) )
	{
		message_vision("但是很显然的，$n现在的状况没有办法给$N任何答覆。\n",
			me, ob);
		return 1;
	}

	if( userp(ob) ) return 1;

	if(topic == WILDCARD)
	{
		message_vision(msg_dunno[random(sizeof(msg_dunno))], me, ob);
		return 1;
	}

	// by Find.
	if( msg = ob->query("inquiry/" + topic,1) )
	{
		if( stringp(msg) )
		{
			message_vision( CYN "$N说道：" + msg + "\n" NOR, ob);
			return 1;
		}

		else if(functionp(msg))
		{
			retn = evaluate(msg,me); // 把动作人作为参数传入。
			if(stringp(retn))
			{
				message_vision( CYN "$N说道：" + retn + "\n" NOR, ob);
				return 1;
			}
			else if(!retn)
			{
				message_vision(msg_dunno[random(sizeof(msg_dunno))], me, ob);
				return 1;
			}
			else
				return retn;
		}
	}

	else if( (topic == ob->name()) || topic == "name" )
		message_vision("$N看了一眼$n说道：我就是$N，你有什么事？\n",ob,me);

        else if( topic == "踏雪无痕" || topic == "dicky" )
                message_vision("$N看了一眼$n说道：他是我们这里的天神，你找他有什么事呢？\n",ob,me);

	if(mapp(ob->query("family")))
	{
		if( topic == ob->query("family/family_name"))
		{
			message_vision("$N朗声说道：提起"+topic+"的名头，江湖上谁不敬服。\n",ob);
			return 1;
		}
	}

	if( mapp(inquirys = ob->query("inquiry"))
	&& member_array(WILDCARD,keys(inquirys)) != -1 )
	{
		msg = ob->query("inquiry/" + WILDCARD,1);
		if( stringp(msg) )
		{
			message_vision( CYN "$N说道：" + msg + "\n" NOR, ob);
			return 1;
		}

		else if(functionp(msg))
		{
			retn = evaluate(msg,me,topic); // 把动作人和topic作为参数传入。
			if(stringp(retn))
			{
				message_vision( CYN "$N说道：" + retn + "\n" NOR, ob);
				return 1;
			}
			else if(!retn)
			{
				message_vision(msg_dunno[random(sizeof(msg_dunno))], me, ob);
				return 1;
			}
			else
				return retn;
		}		
	}

	else
		message_vision(msg_dunno[random(sizeof(msg_dunno))], me, ob);

	return 1;
}

int help(object me)
{
   write( @HELP
指令格式: ask <ID> about <某事>

	问某人关于某件事情。
	可以简写成  wen <ID> gy <某事>

这个指令在解谜时很重要, 通常必须藉由此一指令才能
获得进一步的资讯。
HELP
   );
   return 1;
}
