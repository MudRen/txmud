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
指令格式 : files
 
列出当前每一个档案描述符表。
 
HELP
    );
    return 1;
}
