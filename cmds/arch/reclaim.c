// reclaim.c

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	write("������������� " + reclaim_objects() + " ��������\n");
	return 1;
}

int help(object me)
{
	if(!wizardp(me)) return 0;
write(@HELP
ָ���ʽ : reclaim

�ô� : ������춼����������õı��������, �Լ��ټ������ʹ�á�
HELP
     );
     return 1;
}
