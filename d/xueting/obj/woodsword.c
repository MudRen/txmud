// liuyun-sword.c
// edit by pian

#include <ansi.h>
#include <weapon.h>
inherit SWORD;
inherit F_CONTROL;

void create()
{
	set_name( HIW"ľ��" NOR, ({ "wood sword" }) );
	set_weight(6000);

	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long",@LONG
һ��Ӳľ��ɵĽ����������й��ӵĻ��ƣ����Ѿ����̻�Ѭ��������ڵ��ˡ�
LONG
);

		set("valid_number",3);
		set("value", 300);
		set("material", "wood");
		set("wield_msg", HIW"$N��ˢ����һ�����һ��������ڵ�$n"+HIW"�������С�\n"NOR);
		set("unwield_msg", HIW"$N�����е�$n"+HIW"�������䡣\n"NOR);
//		set("weapon_prop/courage", 10);
//		set("weapon_prop/intelligence", 10);
//		set("weapon_prop/personality", 10);
	
		// װ���˱�����Ҫ��ҵ��书 sword >5 ,parry >5.
		set("wield_skill",([
		"sword" : 5,
		"parry" : 5,
	]));
	
	        /* װ���˱�����Ҫ�������޴��� 50,�����������.
		set("wield_ability",([
		"max_force" : 300,
		"combat_exp" : 50000,
	]));
	*/
}
        init_sword(5);
        setup();
}
