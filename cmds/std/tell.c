// tell.c
// Modified by Find.

#include <ansi.h>
#include <net/dns.h>
#include <net/macros.h>

inherit F_CLEAN_UP;

int help(object me);

int main(object me, string arg)
{
	string target, msg, mud;
	object obj;
	string deny_id;
	int time,count,last_chat;
	mapping mud_list;

	if( !arg || sscanf(arg, "%s %s", target, msg)!=2 ) return help(me);

	if(userp(me))
	{
	if(me->query("channel/chat_block")
	&& (time()-me->query("channel/chat_block"))<0 )
		return notify_fail("你的交谈频道被暂时关闭了。\n");

	time = time();
	count=me->query("channel/chat_count");
	count++;
	last_chat=me->query("channel/last_chat");
	if (count>2)
	{
		count=0;
		me->set("channel/last_chat",time);
		if (time==last_chat && !wizardp(me))
		{
			me->set("channel/chat_block",time+180);
				return notify_fail("因为一次讲话太多，你的交谈频道被暂时关闭了。\n");
		}
	}
	me->set("channel/chat_count",count);
	}

	if( sscanf(target, "%s@%s", target, mud)==2 )
	{
		if(!find_object(DNS_MASTER))
			return notify_fail("网路精灵并没有被载入。\n");
		mud_list = (mapping)DNS_MASTER->query_muds();
		if(!mud_list)
			return notify_fail( "本游戏目前并没有跟网路上其它游戏取得联系。\n");

		mud = htonn(mud);
		if(mud == mud_nname())
			return notify_fail("与本地玩家联系请使用 'tell <某人> <讯息>' 格式。\n");
		if(!mapp(mud_list[mud]))
			return notify_fail("未与此游戏取得联系。\n");

		GTELL->send_gtell(mud, target, me, msg);
		write("网路讯息已送出，可能要稍候才能得到回应。\n");
		return 1;
	}

	obj = find_player(target);
	if(!obj || !me->visible(obj)) return notify_fail("没有这个人....。\n");
	if(obj == me)
		return notify_fail("和自己有什么好说的。\n");

	if(obj->query_temp("netdead"))
		return notify_fail("对方已经断线了，无法听到你的声音。\n");

	if(obj->query_temp("boss_behind"))
		return notify_fail(gender_pronoun(obj->query("gender"))+"的老板正在边上看着"+
		gender_pronoun(obj->query("gender"))+"呢，等一会儿再叫"+
		gender_pronoun(obj->query("gender"))+"吧。\n"); // by Find.

// added by find.
	deny_id = (string)obj->query("env/no_tell");
	if( userp(me) && !wizardp(me) && (deny_id == "all" || deny_id == (string)me->query("id")) )
		return notify_fail(wizardp(obj)?"对方处于封闭工作状态，有事请用 chat 与他联系。\n":
			"对方的 TELL 频道已关闭。\n");
	if( userp(me) && me->query("env/no_tell") && (string)me->query("env/no_tell") == "all" )
	{
		me->set("env/no_tell",0);
		write(HIY "你的 TELL 频道被打开了。\n" NOR);
	}
// over.

	write(BWHT GRN"你告诉" + obj->name(1) + "：" + msg + "\n" NOR);
	tell_object(obj, sprintf(BWHT HIB"%s告诉你：%s\n" NOR,
		me->name(1)+"("+me->query("id")+")", msg));

	obj->set_temp("reply", me->query("id"));
	return 1;
}

int remote_tell(string cname, string from, string mud, string to, string msg)
{
	object ob;

	if(objectp(ob = find_player(to))
	&& !(wizardp(ob) && ob->query("env/invisibility"))) {
		if( cname )
			tell_object(ob, sprintf(BWHT HIB"%s(%s@%s)告诉你：%s\n" NOR,
				cname, capitalize(from), mud, msg ));
		else
			tell_object(ob, sprintf(BWHT HIB"%s@%s 告诉你：%s\n" NOR,
				capitalize(from), mud, msg ));
		ob->set_temp("reply", from + "@" + mud);
		return 1;
	} else
		return 0;
}

int help(object me)
{
	write(@HELP
指令格式：tell <某人> <讯息>

你可以用这个指令和其他地方的使用者说话。

其他相关指令：reply
HELP
	);
	return 1;
}
