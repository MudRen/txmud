// feixu.c
// �軨���� feixu
// Ʈ�경��(piaoyu-steps)���ع�

#include <ansi.h>

inherit SSERVER;

int perform(object me, object target)
{
	int skill,num,force,up,time;

	if(me->is_busy())
		return notify_fail("����һ������û����ɣ��޷�ʹ�á��軨��������\n");

	if(me->query_temp("block-piaoyu-step"))
		return notify_fail("������Ѿ����������ޣ����軨�������Ѿ�û���ô��ˡ�\n");

	if((skill = me->query_skill("piaoyu-steps",1)) < 100)
		return notify_fail("��Ʈ�경���������죬�޷�ʹ�á��軨��������\n");

	num = (skill - 100)/40 + 1;

	force = (num+1)*100;	// ��Ҫ������
	if(me->query("force") < force)
		return notify_fail("�������������޷�ʹ�á��軨��������\n");

	time = 120 + (30*num);	// ά�ֵ�ʱ��
	if(num > 5)
		num = 5;

	up = 10 + (num * 10);

	message_vision(sprintf("$NĬ�Ʈ�경������Ҫ�������ζ�ת��ʩչ��%s��\n",
		BWHT HIG"���軨������"NOR),me);

	me->add_temp("apply/defense",up);
	me->add("force",-force);
	me->set_temp("block-piaoyu-step",1);

	me->start_busy(1);

	// start_perform_busy() Ϊʹ�� perform �ļ������λΪ��������
	// ÿ�� perform �����д����ã�����perform �ǲ�������ʹ�õġ�
	me->start_perform_busy(15);

	call_out("stop_up",time,me,up);

	return 1;
}

private void stop_up(object who,int up)
{
	if(!objectp(who) || (up <= 0) )
		return;

	who->add_temp("apply/defense",-up);
	who->delete_temp("block-piaoyu-step");

	tell_object(who,HIG"��о�������������������������š��軨�������Ĺ�Ч�Ѿ���ʧ�ˡ�\n"NOR);
}

int clean_up()
{
	if(find_call_out("stop_up") >= 0)
		return 1;
	return ::clean_up();
}
