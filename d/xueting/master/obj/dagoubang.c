// dagoubang.c
// edit by pian

#include <ansi.h>
#include <weapon.h>
inherit STAFF;
inherit F_CONTROL;

void create()
{
	set_name( HIY"������" NOR, ({ "dagoubang" }) );
	set_weight(6000);

	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long",@LONG
��������ؤ����������ഫ������ʵ����죬�ǽ��
��ͨ����̣��������ߴ磬�볤һ��һ���нڡ����ۡ�
�Ӷ��������ࡣ���ȴ�˵�е������ܶϣ�ˮ�����֡�
��������ʹ�û�����һЩ��Ϊ���ܵĹ�Ч��
LONG
);

		set("valid_number",1);
		set("value", 9000);
		set("material", "blacksteel");
		set("wield_msg", HIR"$N��ˢ����һ�����һ���������̹����$n"+HIR"�������С�\n"NOR);
		set("unequip_msg", HIR"$N�����е�$n"+HIR"���뻳�С�\n"NOR);
		set("weapon_prop/courage", 10);
		set("weapon_prop/intelligence", 10);
		set("weapon_prop/personality", 10);
	
		// װ���˱�����Ҫ��ҵ��书 sword >90 ,parry >90.
		set("wield_skill",([
		"staff" : 90,
		"parry" : 90,
	]));
	
	        // װ���˱�����Ҫ�������޴��� 300,�����������.
		set("wield_ability",([
		"max_force" : 1000,
		"combat_exp" : 500000,
	]));
}
        init_staff(90);
        setup();
}
