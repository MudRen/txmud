// weixiao.c �л�΢Ц
// by dicky

#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
        object  weapon;
	string  msg;
        int damage,ap;
	
	weapon = me->query_temp("weapon");

	if (! target) target = offensive_target(me);

	if (! target 
	|| !target->is_character() 
	|| ! me->is_fighting(target))
		return notify_fail("�л�΢Цֻ�ܶ�ս���еĶ���ʹ�á�\n");
	                        
        if ((int)me->query("force", 1) < 800)
		return notify_fail("����������̫��������ʹ�òл�΢Ц��\n");

        if (!weapon || weapon->query("skill_type") != "sword"
        || me->query_skill_mapped("sword") != "fenghui-sword")
                return notify_fail("�������ʹ�ý�ʱ����ʹ�����л�΢Ц����\n");

        if (me->query_skill_mapped("force") != "taxue-force")
                return notify_fail("���л�΢Ц����Ҫʹ��̤ѩ�񹦡�\n"); 

	if (! living(target))
              return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

	msg = HIC "$N����" + weapon->name() + HIC "��һȦȦ�Ļ���$n��" HIC "��$p���ڵ��У�\n" NOR;
	me->add("force", -50);

        ap = me->query_skill("fenghui-sword", 1) * 3 / 2 +
             me->query_skill("force", 1);

	damage = ap / 2 + random(ap / 2);

        if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/5 )
        {
                msg += HIR "$n" HIR "��æ��Ų������Ȼ�������ꡱһ����" + weapon->name() +"���û���$p" HIR "��Ҫ����$p" HIR "һ���ҽУ�����������\n" NOR;            
		target->receive_damage("kee",damage,me);
		me->add("force", -400);
		me->start_busy(1);
	}
	else 
	{
		msg += CYN "����$p" CYN "������$P" CYN "�ı仯�����в��У�û���ܵ��κ��˺���\n"NOR;
                me->add("force", -300);
		me->start_busy(1);
	}

	message_vision(msg, me, target);
	me->start_perform_busy(8);
	return 1;
}
