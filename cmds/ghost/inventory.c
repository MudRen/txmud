//inventory.c
// װ�������ֵı�����'��'��ʾ.
// Modified by Find.

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	return "/cmds/usr/inventory"->main(me,arg);
}

int help (object me)
{
        write(@HELP
ָ���ʽ: inventory
 
���г���Ŀǰ������Я����������Ʒ��

"��" ���˵������ƷΪ���Ѿ�װ��
     �ı��������Ѵ����Ļ��ס�
"��" ���˵���˱���װ����������֡�

ע : ��ָ����� " i " ���档
 
HELP
);
        return 1;
}
