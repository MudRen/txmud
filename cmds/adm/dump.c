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
ָ���ʽ : dump
 
������������������б������ /OBJ_DUMP ��������

HELP
    );
    return 1;
}
 
