// exercise.c

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
        int kee_cost, rn;

        if( me->query_temp("exercise"))
		return notify_fail("�������Ѿ������˹�״̬���������˹��ˡ�\n");

	if( me->is_fighting() )
                return notify_fail("ս���в������ڹ������߻���ħ��\n");

	if( !stringp(me->query_skill_mapped("force")) )
                return notify_fail("��������� enable ѡ����Ҫ�õ��ڹ��ķ���\n");

        if( !arg || !sscanf(arg, "%d", kee_cost) )
                return notify_fail("��Ҫ��������������\n");

	if( kee_cost < 10 )
		return notify_fail("������Ҫ�� 10 �㡸��������������\n");

        if( (int)me->query("kee") < kee_cost )
                return notify_fail("�����ڵ���̫���ˣ��޷�������Ϣ����ȫ������\n");

        if( (int)me->query("sen") * 100 / (int)me->query("max_sen") < 70 )
                return notify_fail("�����ھ���״��̫���ˣ��޷�����רһ��\n");

        if( (int)me->query("gin") * 100 / (int)me->query("max_gin") < 70 )
                return notify_fail("�����ھ����������޷�������Ϣ��������\n");

        write("�������������۾������ù���һ����Ϣ��ʼ������������\n");

	rn=random(3);
	me->start_busy(5);
	call_out("do_exercise",3+rn,me,kee_cost);
	return 1;
}

private void do_exercise(object me,int kee_cost)
{
	int force_gain;
        me->receive_damage("kee", kee_cost);
        message_vision("$N�й���ϣ������������۾���վ��������\n", me);

	if(!objectp(me))
		return;

        force_gain = kee_cost * ((int)me->query_skill("force",1)+ 25 ) / 400;

	seteuid(getuid());

	if( force_gain < 1 )
		tell_object(me,"������ֻ����ȫ���飬�����������������̫���ˡ�\n");
	else
	{
		me->add("force", force_gain );
		if( (int)me->query("force") > (int)me->query("max_force") * 2)
		{
			if( (int)me->query("max_force") >= ((int)me->query_skill("force", 1) +
			(int)(me->query_skill("force")/3) ) * 10 )
			{
				me->set("force", me->query("max_force")*2);
				tell_object(me,"�������������û���κ������ļ����ƺ�������Ϊ�Ѿ�������ƿ����\n");
			}
			else
			{
				write(HIC"���������ǿ�ˣ�\n"NOR);
				me->add("max_force", 1);
				me->set("force", me->query("max_force"));
			}
		}
	}

	me->stop_busy();
}

int help(object me)
{
        write(@HELP
ָ���ʽ : exercise [<�ķѡ�����������Ԥ��ֵ 30>]
           exercise �ɼ�дΪ dazuo

���������������������ڵ����ڸ�����������������ѵ����
�弡�����������������������������������ʽ����������
������

��ο� help stats
HELP
        );
        return 1;
}
