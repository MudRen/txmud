// liu.c
// ������Ӱ liu
// ������Ӱ����[liuhua-sword]���ع�

#include <ansi.h>
#include <combat.h>

inherit SSERVER;

int perform(object me, object target)
{
	int skill, kee;
	object weapon;

	if((skill = me->query_skill("liuhua-sword",1)) < 100)
		return notify_fail("���������Ӱ�����������죬�޷�ʹ�á�������Ӱ����\n");

	if( !target )
		target = offensive_target(me);
	if( !target
	|| !target->is_character()
	|| !me->is_fighting(target) )
		return notify_fail("��������Ӱ��ֻ�ܶ�ս���еĶ���ʹ�á�\n");

	if(me->query("force") < 200 )
		return notify_fail("��Ŀǰ���������㣬�޷�ʩչ��������Ӱ����\n");

	me->add("force",-200);

	if(!weapon = me->query_temp("weapon"))
		return notify_fail("���޷�ʩչ��������Ӱ����\n");

	message_vision(sprintf("$N�����Ҷ����ó�һƬ��⣬ʩչ�����ž�ѧ��������Ӱ����\n", weapon),me,target);
	kee = target->query("kee");
      for(int i=0;i<5;i++)
	{
		COMBAT_D->do_attack(me,target,TYPE_QUICK);
	}

	if(target->query("kee") < kee)
		target->apply_condition("weapon_bleeding", 6);

	me->start_busy(1);

	// start_perform_busy() Ϊʹ�� perform �ļ������λΪ��������
	// ÿ�� perform �����ɴ����ã�����perform �ǲ�������ʹ�õġ�
     me->start_perform_busy(9);
	return 1;
}
