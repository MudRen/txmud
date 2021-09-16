// say.c
// Modified by Find.

#define TIME_DISTANCE	15
#define CHAT_NUM	10
/* 15 秒钟之内说话超过 10 句,关频道 */

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	int time,count,last_chat;

	if(userp(me))
	{
	time=time();
	if(me->query("channel/chat_block")
	&& (time-me->query("channel/chat_block"))<0 )
		return notify_fail("你的交谈频道被暂时关闭了。\n");

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
	}

	if (!arg) {
		write("你自言自语不知道在说些什麽。\n");
		message("sound", me->name() + "自言自语不知道在说些什麽。\n",
			environment(me), me);
		return 1;
	}
	if( (int)me->query("kee") < (int)me->query("max_kee") / 5 ) {
		arg = replace_string(arg, " ", " ... ") + " ...";
	}

	write( CYN "你说道：" + arg + "\n" NOR);
	message("sound", CYN + me->name() + "说道：" +  arg + "\n" NOR,
		environment(me), me);

	// The mudlib interface of say
	all_inventory(environment(me))->relay_say(me, arg);

	return 1;
}

int help (object me)
{
	write(@HELP
指令格式: say <讯息>
 
说话，所有跟你在同一个房间的人都会听到你说的话。
 
注: 本指令可用 ' 取代.
 
HELP
	);
	return 1;
}
