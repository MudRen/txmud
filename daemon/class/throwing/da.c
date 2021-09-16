// da.c
// ���� (throwing �Ĺ���)

#include <combat.h>

inherit SSERVER;

int perform(object me, object target, int left_hand)
{
	int num, ap, dp, damage;
	object weapon;
	string dskill;

	if(me->is_busy())
		return notify_fail(BUSY_MESSAGE);

	if( !target )
		target = offensive_target(me);
	if( !target
	|| !target->is_character()
	|| !me->is_fighting(target) )
		return notify_fail("ֻ�ܶ�ս���еĶ��ִ�����\n");

	if(left_hand)
		weapon = me->query_temp("secondary_weapon");
	else
		weapon = me->query_temp("weapon");

	if(weapon->query("skill_type") != "throwing")
		return notify_fail(sprintf("%s���ܵ����������á�\n", weapon->name()));

	if((num = weapon->query_amount()) < 1)
	{
		weapon->unequip();
		destruct(weapon);
		return notify_fail("��Ҫ��ʲô������\n");
	}

	ap = COMBAT_D->skill_power(me,"throwing",SKILL_USAGE_ATTACK);
	dp = COMBAT_D->skill_power(target,"dodge",SKILL_USAGE_DEFENSE)/2 + COMBAT_D->skill_power(target,"perception",SKILL_USAGE_DEFENSE);

	damage = weapon->query("weapon_prop/damage")/2;

	message_vision(sprintf("$N%s��һ�һ%s%s��$n�����ȥ��\n",
		left_hand?"��":"��", weapon->query("base_unit"), weapon->name()),
		me, target);

	if(random(ap + dp) >= dp)	// ����
	{
		weapon->weapon_effect(me, target, damage);
		target->receive_damage("kee", damage+random(damage), me);
		if(damage = random(damage/2))
			target->receive_wound("kee", damage, me);
		COMBAT_D->report_status(target);
	}
	else
	{
		dskill = target->query_skill_mapped("dodge");
                if(!dskill)
			dskill = "dodge";
		message_vision(SKILL_D(dskill)->query_dodge_msg(), me, target);
	}

	if(num == 1)
	{
		weapon->unequip();
		tell_object(me, sprintf("\n���%s�����ˡ�\n\n", weapon->name()));
	}
	weapon->add_amount(-1);

	if(userp(me))
	{
		me->start_busy(1);
		me->start_perform_busy(2);
	}

	return 1;
}
