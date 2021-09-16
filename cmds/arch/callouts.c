// callouts.c

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	mixed *info;
	int i;
	string output;

	output = sprintf("%-45s %-20s %5s \n", "���", "����", "�ӳ�ʱ��"); 
	if( arg && arg!="" )
		info = filter_array(call_out_info(), (: $1[1]==$2 :), arg);
	else
		info = call_out_info();

	for(i=0; i<sizeof(info); i++)
		output += sprintf("%-45O %-20s %5d \n",
			info[i][0], info[i][1], info[i][2] );

	me->start_more(output);
	return 1;
}

int help()
{
	write(@LONG
ָ���ʽ��callouts [<��������>]

ȡ�õ�ǰϵͳ������ʹ�� call_out() ���ж��ӳ��еĺ���������Ѷ��
Ҳ����ָ����������ȡ���ض��ĺ���������Ѷ��

LONG
	);
	return 1;
}