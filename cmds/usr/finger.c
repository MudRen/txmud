// finger.c

inherit F_CLEAN_UP;

int main(object me, string arg)
{
        if( !arg )
	{
		if( ((int)me->query("sen") < 10) && !wizardp(me) )
			return notify_fail("��ľ����޷����С�\n");
		if( !wizardp(me) )
		{
			me->receive_damage("sen", 10,"tire");
			me->start_more( FINGER_D->finger_all(0) );
		}
		else
			me->start_more( FINGER_D->finger_all(1) );

	}
	else
	{
		if( ((int)me->query("sen") < 5) && !wizardp(me) )
			return notify_fail("��ľ����޷����С�\n");
		if( !wizardp(me) )
			me->receive_damage("sen", 5);
		write( FINGER_D->finger_user(arg) );
	}
	return 1;
}

int help(object me)
{
  write(@HELP
ָ���ʽ : finger [ʹ��������]
 
���ָ��, ���û��ָ��ʹ��������, ����ʾ�����������������
����������. ��֮, �����ʾ�й�ĳ����ҵ�����, Ȩ�޵�����.
 
see also : who
HELP
    );
    return 1;
}
