// tan.c
// ����̽��

#include <ansi.h>
#include <combat.h>

inherit SSERVER;

int perform(object me, object target)
{
	int extra, msen;
	object weapon;

	if(me->is_busy())
		return 0;

	extra = me->query_skill("feilong-quan",1);
	if ( extra < 50)
		return notify_fail("��ķ�������ȭ���������죡\n");

	if( !target )
		target = offensive_target(me);
	if( !target
	|| !target->is_character()
	|| !me->is_fighting(target) )
		return notify_fail("��������ȭֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (me->query("force")<=100)
		return notify_fail("����������㣬�޷�ʹ�÷���̽��\n");

	if(objectp(weapon = me->query_temp("weapon")))
		return 0;

        me->add("force",-100);
        me->start_busy(1);
	msen = target->query("max_sen")/20;

	message_vision(HIY "\n$N���һ����ʹ����������ȭ�ľ��С�����̽������\n" NOR,me,target);
	if( random(me->query("combat_exp")/30*extra) > (int)target->query("combat_exp")*7/2 ) 
	{
		for(int i=0;i<4;i++)
		{
			COMBAT_D->do_attack(me,target,TYPE_QUICK);
			target->receive_wound("sen", msen, me);
		}
		return 1;

	}

	else
		message_vision("$n���һ�ݶ㿪���У���Ҳ�ų���һ���亹��\n" NOR, me, target);
	return 1;
}
