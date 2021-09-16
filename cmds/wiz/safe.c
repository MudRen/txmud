// safe.c
// by Find.
// 测试用命令

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	int flag = 1;
	object guarded;

	if( (me != this_player(1)) || (wiz_level(me) < wiz_level("wizard")) )
		return notify_fail("You have NO right to user this command.\n");

	if(!arg || !stringp(arg) || (sizeof(arg) < 3))
		return 0;

	if(arg[0..1] == "-d")
	{
		arg = arg[3..];
		flag = 0;
	}

	if(!objectp(guarded = present(arg,environment(me))) || !userp(guarded))
		return notify_fail("使用错误。\n");

	if(!flag && !guarded->in_wizard_guard())
		return notify_fail(guarded->name()+"并没有在巫师的保护之下。\n");

	seteuid(getuid());

	guarded->set_wizard_guard_flag(flag);

	if(me == guarded)
		message_vision(!flag?HIC"$N单手一挥，$N身边的蓝烟消失了。\n"NOR:
			HIB"$N中指一弹，一道淡淡的蓝烟罩在了$N的周围。\n"NOR,me);
	else
		message_vision(!flag?HIC"$N单手一挥，$n身边的蓝烟消失了。\n"NOR:
			HIB"$N中指一弹，一道淡淡的蓝烟罩在了$n的周围。\n"NOR,me,guarded);

	if(!wizardp(guarded))
		log_file("safe",sprintf("<%s> safe <%s>. %s\n",geteuid(me),geteuid(guarded),ctime(time())));

	return 1;
}
