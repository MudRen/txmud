// files.c

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	me->start_more(dump_file_descriptors());
	return 1;
}


int help(object me)
{
        write(@HELP
ָ���ʽ : files
 
�г���ǰÿһ��������������
 
HELP
    );
    return 1;
}
