// ����˫��
// by dicky

#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
	int j;

	j = me->query_skill("xianglong-zhang")/2;
	if( !target ) target = offensive_target(me);
	if( !target || !me->is_fighting(target) || !living(target))
                return notify_fail("������˫�ơ�ֻ����ս���жԶ���ʹ�á�\n");

        if( objectp(me->query_temp("weapon")) )
                return notify_fail("�������ֲ���ʹ�á�����˫�ơ���\n");

        if( (int)me->query_skill("xianglong-zhang", 1) < 160 )
                return notify_fail("��Ľ���ʮ���ƻ�������죬ʹ����������˫�ơ�������\n");

        if( (int)me->query_skill("gaibang-force", 1) < 160 )
                return notify_fail("���ؤ���ķ��ȼ���������ʹ����������˫�ơ�������\n");

        if (me->query_skill_mapped("force") != "gaibang-force")
                return notify_fail("����ʹ�õ��ڹ����ԡ�\n");
        if( (int)me->query_skill("force") < 200 )
                return notify_fail("����ڹ��ȼ�����������ʹ�á�����˫�ơ���\n");

        if( (int)me->query_str() < 24 )
                return notify_fail("�������������ǿ����ʹ����������˫�ơ�����\n");

        if (me->query_skill_mapped("unarmed") != "xianglong-zhang"
        || me->query_skill_mapped("parry") != "xianglong-zhang")
                return notify_fail("�������޷�ʹ�á�����˫�ơ���\n");                                                                                 

	if( (int)me->query("max_force") < 1200)
		return notify_fail("����������̫����ʹ����������˫�ơ���\n");     

	if( (int)me->query("force") < 800 )
		return notify_fail("����������̫����ʹ����������˫�ơ���\n");

//	if((int)me->query_temp("xlz") ) 
//		return notify_fail("������ʹ�ý���Х��\n");

        message_vision(WHT"\n$Nһ���Ϻȣ�˫�������Ю�������ɳ��ʹ����������ĵ��⹦������˫�ơ���\n"NOR,me);

        me->add_temp("apply/unarmed", j);
        me->add_temp("apply/damage", j);
        me->add_temp("apply/attack", j/2);

	for(int i=0;i<6;i++)
	{
		COMBAT_D->do_attack(me,target,TYPE_QUICK);
		target->receive_wound("sen", 10);
	}

        me->add_temp("apply/unarmed", -j);
        me->add_temp("apply/damage", -j);
        me->add_temp("apply/attack", -j/2);
        me->add("force", -600);
        me->add("gin", -100);
        me->start_busy(2);
        target->start_busy(1+random(2));
        return 1;
}
