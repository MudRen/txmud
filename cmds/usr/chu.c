// /cmds/usr/chu.c
// by Find.

inherit F_CLEAN_UP;

protected int MAX = 20000000;

int main(object me,string arg)
{
	int s_num,value,per_chu,min_value;
	object who;

        if(wizardp(me))
                return notify_fail("��ʦ������μӾ���\n");

	seteuid(getuid());

	if(!PAWN_D->query_being_meeting())
	{
		object sroom;

		sroom = find_object("/d/changan/selling_room");
		if(!sroom || !sroom->is_selling())
			return 0;

		s_num = atoi(arg);
		if((s_num < 1) || (s_num > MAX))
			return notify_fail("��Ҫ�����������Ӿ������ڽ�������Ʒ��\n");

		if(sroom->accept_chu(me, s_num))
		{
			me->set_temp("be_in_sale_meeting_chu",1);
			return 1;
		}

		return 0;
	}

	if(PAWN_D->query_num_during_meeting() == -1)
		return notify_fail("��û�п�ʼ�����أ����һ����ٳ��۰ɡ�\n");

	if(PAWN_D->query_unvalid_flag())
		return notify_fail("��ǰ��Ʒ�Ѿ�����ȥ�ˣ������һ����Ʒ�ɡ�\n");

	s_num = atoi(arg);
	if((s_num < 1) || (s_num > MAX))
		return notify_fail("��Ҫ�����������ӹ���������������Ʒ��\n");

	value = PAWN_D->query_current_value();
	per_chu = PAWN_D->query_min_value_per_chu();
	who = PAWN_D->query_current_user();

	if(who)
	{
		if(who == me)
			return notify_fail("���ڵļ�Ǯ��������ģ�Ŀǰ��û���˺������������ټӼ��ˡ�\n");
		else
			min_value = to_int(ceil((value+per_chu)/100));
	}
	else
		min_value = to_int(ceil(value/100));

	if(s_num < min_value)
		return notify_fail(sprintf("����ǰ��Ʒ����Ҫ�� %d �����ӡ�\n",min_value));

	if(!pay_from_bank(me,s_num*100,1))
		return notify_fail("��������Ŀǰû����ô���\n");

	PAWN_D->accept_chujia(me,s_num*100);

	write(sprintf("����� %d �����ӲμӾ���\n",s_num));

	me->set_temp("be_in_sale_meeting_chu",1);
	return 1;
}


int help(object me)
{
        write(@HELP
ָ���ʽ : chu <������>

��ָ����������������ڼ��������ҽ���ʱ��
�Ե�ǰ�ľ�����Ʒ���ۡ�

���磺
	chu 1000

��Ը�� 1000 ����������ǰ���ھ������Ʒ��
��Ȼ������������Ҫ����ô���

HELP
    );
    return 1;
}
