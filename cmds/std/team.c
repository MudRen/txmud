// team.c
// by Find

#define MAX_TEAM_MEMBER	4

#include <ansi.h>

inherit F_CLEAN_UP;

int help(object);

int main(object me, string arg)
{
	object *t, leader;
	if( !arg )
	{
		if( !me->in_team() )
			return notify_fail("�����ڲ�û�вμ��κζ��顣\n");

		if((leader = me->query_team_leader()) == me)
			printf("�����Ķ����еĳ�Ա�У�\n  %s\n\n",
				implode(me->query_team_member()->name(1), "\n  "));
		else
			printf("������%s����Ķ����У���Ա�У�\n  %s\n\n",
				leader->name(1), implode(me->query_team_member()->name(1), "\n  "));
		return 1;
	}

	// ��������죬���ǽ�ɢ����
	// �ǳ�Ա���������
	if( arg=="san" )
	{
		if( !me->in_team() )
			return notify_fail("�����ڲ�û�вμ��κζ��顣\n");

		if( me->is_team_leader() )
		{
			message("team", me->name(1) + "�������ɢ�ˡ�\n", me->query_team_member(), me);
			write("�㽫�����ɢ�ˡ�\n");
		}

		else
		{
			message("team", me->name(1) + "�����뿪���顣\n", me->query_team_member(), me);
			write("���뿪�˶��顣\n");
		}

		me->dismiss_team();
		return 1;
	}

	// ����
	if( sscanf(arg, "yq %s", arg)==1 )
	{
		object ob;
		int m_exp, o_exp;

		if(me->in_team())
		{
			if(!me->is_team_leader())
				return notify_fail("ֻ�ж����������������˼��롣\n");
			if(sizeof(me->query_team_member()) >= MAX_TEAM_MEMBER)
				return notify_fail("��Ķ��������Ѿ��ﵽ�����������\n");
		}

		if( !(ob = present(arg, environment(me)))
		|| !living(ob)
		|| !userp(ob)
		|| (ob==me) )
			return notify_fail("��������˭������Ķ��飿\n");

		if( (wizardp(me) && !wizardp(ob))
		|| (!wizardp(me) && wizardp(ob)) )
			return notify_fail("��ʦ����Ҳ�����ӡ�\n");

		if(ob->in_array())
			return notify_fail("�Է��������������У��޷��μ���Ķ��顣\n");

		m_exp = me->query("combat_exp");

		if( ((o_exp = ob->query("combat_exp")) < m_exp/10*8)
		|| (o_exp > m_exp*1.2) )
			return notify_fail(ob->name()+"�ľ����������Զ���޷���ɶ��顣\n");

		if(me->is_team_member(ob))
			return notify_fail(ob->name()+"�Ѿ��������ĳ�Ա�ˡ�\n");

		if(ob->in_team())
			return notify_fail(ob->name()+"�Ѿ�����������ĳ�Ա�ˡ�\n");

		if(ob->in_array())
			return notify_fail(sprintf("%s��%s�ĳ�Ա�����ܼ�����Ķ��顣\n",
				ob->name(), ob->query_array_name()));

		message_vision("$N����$n����$P�Ķ��顣\n", me, ob);
		tell_object(ob, sprintf(BWHT HIG"�����Ը������� team in %s ������롣\n"NOR, me->query("id")));
		ob->set_temp("pending/team", me);
		return 1;
	}

	// ����
	if( sscanf(arg, "in %s", arg)==1 )
	{
		object ob = me->query_temp("pending/team");
		int m_exp, o_exp;

		if(!ob || !arg)
			return notify_fail("��û�������㷢����ӵ����롣\n");

		if(geteuid(ob) != arg)
			return notify_fail(arg+"����˲�û�����㷢����ӵ����롣\n");

		if(sizeof(ob->query_team_member()) >= MAX_TEAM_MEMBER)
				return notify_fail("�Է����������Ѿ��ﵽ������������㲻���ټ����ˡ�\n");

		if(me->in_array())
			return notify_fail("���������У��޷����������Ķ��顣\n");

		m_exp = ob->query("combat_exp");
		if( ((o_exp = me->query("combat_exp")) < m_exp/10*8)
		|| (o_exp > m_exp*1.2) )
			return notify_fail(sprintf("��ľ����%s����Զ���޷���ɶ��顣\n", ob->name()));

		if(me->in_team())
			return notify_fail(sprintf("���Ѿ���%s����ĳ�Ա�ˡ�\n",
				(me->query_team_leader()==ob)?"":"����"));

		if(me->in_array())
			return notify_fail(sprintf("����%s�ĳ�Ա�����ܼ��������Ķ��顣\n",
				me->query_array_name()));

		ob->add_team_member(me);
		printf("��Ӧ��������%s����Ķ��顣\n", ob->name());
		me->delete_temp("pending/team");
		return 1;
	}

	if( sscanf(arg, "talk %s", arg)==1 )
	{
		if( !me->in_team() || !sizeof(t=me->query_team_member()) )
			//return notify_fail("�����ڲ�û���ڶ����С�\n");
			return 0;

		message("team", sprintf(HIW "�����顿%s��%s\n" NOR,me->name(1),arg), t);
		return 1;
	}

	return help(me);
}

int help(object me)
{
	write(@HELP
����ָ��ʹ�÷���:

team		��ʾ�����ڵĶ���ĳ�Ա������

team san	����������ɢ���齨�Ķ��顣
		������ɼ�дΪ��ts

team yq <ID>	��������ĳ�˼�����Ķ��顣
		�������˵ľ���������ܳ��� 20% ��
		������ɼ�дΪ��tyq

team in <ID>	�������������顣
		������ɼ�дΪ��tin

team talk	�����Ա֮��Ľ�̸��
		������ɼ�дΪ��tt

HELP
	);
	return 1;
}
