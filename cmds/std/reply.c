// reply.c
// Modified by Find.

#include <ansi.h>
#include <net/dns.h>

inherit F_CLEAN_UP;

int help(object me);

int main(object me, string arg)
{
	string target, mud, deny_id;
	object obj;
	int time,count,last_chat;

	if(me->query("channel/chat_block")
	&& (time()-me->query("channel/chat_block"))<0 )
		return notify_fail("你的交谈频道被暂时关闭了。\n");

	if( !arg || arg=="" )
		return notify_fail("你要回答什么？\n");

	if( !stringp(target = me->query_temp("reply")) )
		return notify_fail("刚才没有人和你说过话。\n");

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

	if( sscanf(target, "%s@%s", target, mud)==2 ) {
		GTELL->send_gtell(lower_case(mud), lower_case(target), me, arg);
		write("网路讯息已送出，可能要稍候才能得到回应。\n");
		return 1;
	}

	obj = find_player(target);
	if( !obj )
		return notify_fail("刚才和你说话的人现在无法听见你，或者已经离开游戏了。\n");

	if(obj->query_temp("netdead"))
		return notify_fail("对方已经断线了，无法听到你的声音。\n");

	if(obj->query_temp("boss_behind"))
		return notify_fail(gender_pronoun(obj->query("gender"))+"的老板正在边上看着"+
		gender_pronoun(obj->query("gender"))+"呢，等一会儿再回答"+
		gender_pronoun(obj->query("gender"))+"吧。\n"); // by Find.

	deny_id = (string)obj->query("env/no_tell");
	if( userp(me) && !wizardp(me) && (deny_id == "all" || deny_id == (string)me->query("id")) )
		return notify_fail(wizardp(obj)?"对方处于封闭工作状态，有事请用 chat 与他联系。\n":
			"对方的 TELL 频道已关闭。\n");
	if( userp(me) && me->query("env/no_tell") && (string)me->query("env/no_tell") == "all" )
	{
		me->set("env/no_tell",0);
		write(HIY "你的 TELL 频道被打开了。\n" NOR);
	}

	write(BWHT GRN"你回答" + obj->name(1) + "：" + arg + "\n" NOR);
	tell_object(obj, sprintf(BWHT HIB"%s回答你：%s\n"NOR,
		me->name(1), arg ));

	obj->set_temp("reply", me->query("id"));
	return 1;
}

int help(object me)
{
	write(@HELP
指令格式：reply <讯息>

你可以用这个指令和刚才用 tell 和你说话的使用者说话。

see also : tell
HELP
	);
	return 1;
}
