// yujian.c Ԧ������
// by dicky

#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int exert(object me, object target)
{
        object weapon;
	
	weapon = me->query_temp("weapon");

	if (! target) target = offensive_target(me);

        if (me->query_skill_mapped("force") != "taxue-force")
                return notify_fail("��Ԧ��������Ҫʹ��̤ѩ�񹦡�\n"); 

        if(me->query_skill("taxue-force", 1) < 300 )
                return notify_fail("���̤ѩ�񹦻�������죬ʹ������Ԧ������������\n");

        if(me->query_skill("fenghui-sword", 1) < 300 )
                return notify_fail("��ķ��ѩ�轣����������죬ʹ������Ԧ������������\n");

        if ((int)me->query("max_force", 1) < 3000)
		return notify_fail("����������̫��������ʹ��Ԧ������\n");

        if ((int)me->query("force", 1) < 1000)
		return notify_fail("����������̫��������ʹ��Ԧ������\n");

        if ((int)me->query("max_mana", 1) < 1500)
		return notify_fail("�����ڷ���̫�����ʹ��Ԧ������\n");

        if ((int)me->query("mana", 1) < 1000)
		return notify_fail("�����ڷ���̫��������ʹ��Ԧ������\n");

        if ((int)me->query("max_atman", 1) < 1500)
		return notify_fail("����������̫�����ʹ��Ԧ������\n");

        if ((int)me->query("atman", 1) < 1000)
		return notify_fail("����������̫��������ʹ��Ԧ������\n");

	if (!me->query("taxue/yujian_pass"))
		return notify_fail("�����ڻ�����ʹ��Ԧ������\n");

	message_vision (HIR"\n\n$N����������ǰ��ʳָ��ֱָ����գ����������дʣ�ͻȻ���һ�������𣡡�\n\n��̼䣬����ʱ߷���һ��������$Nһ�����ɺ�չ�ᡱ��˳�ְ����������У�\n\n"NOR, me);

	new("/d/taxue/obj/sword1")->move(me);

	me->add("force",-400);
	me->add("mana",-300);
	me->add("atman",-300);
	me->start_busy(2);
	return 1;
}