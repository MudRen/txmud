// dump.c (should be admin cmd?)

inherit F_CLEAN_UP;

int main(object me,string arg)
{
	seteuid(geteuid(me));

    dumpallobj();

	return 1;
}

int help(object me)
{
	write(@HELP
指令格式 : dump
 
将所有已载入物件的列表输出到 /OBJ_DUMP 这个档案里。

HELP
    );
    return 1;
}
 
