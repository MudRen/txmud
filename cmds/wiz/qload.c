// qload.c
// Modified by Find.

inherit F_CLEAN_UP;

int main()
{
	float cmds,comp;

	sscanf(query_load_average(),"%f cmds/s, %f comp lines/s",cmds,comp);

	write(sprintf("ƽ��ÿ����� %.2f ��ʹ�������ÿ����� %.2f �г���\n",
		cmds,comp));

	return 1;
}

int help(object me)
{
write(@HELP
ָ���ʽ : qload 

���ָ����ʾ��Ŀǰ CPU �ĸ�����
HELP
    );
    return 1;
}
