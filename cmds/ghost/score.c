// score.c
// by Find.

inherit F_CLEAN_UP;

int main(object me,string arg)
{
	return "/cmds/usr/score"->main(me,arg);
}

int help(object me)
{
	write("指令格式 : score\n"
+((wizardp(me))?"           score <对象名称>\n\n":"\n")
+"这个指令可以显示你"+((wizardp(me))?"或指定对象(含怪物)":"")+"的基本资料。\n"
+"see also : hp\n");
    return 1;
}