// skills.c

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	return "/cmds/usr/skills"->main(me,arg);
}

int help(object me)
{
	write(@HELP
指令格式 : skills [<某人>]

这个指令可以让你查询你所学过的技能。

你也可以指定一个和你有师徒或婚姻关系的对象，
用 skills 可以查知对方的技能状况。

HELP
    );
    return 1;
}
