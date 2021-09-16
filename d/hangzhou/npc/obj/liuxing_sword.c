// liuxing_sword.c

#include <weapon.h>

inherit SWORD;
inherit F_CONTROL;

void create()
{
	set_name("���Ǹ��½�", ({ "liu xing sword" }) );
	set_weight(10000);
	set("valid_number",10); // 10��

	if( clonep() )
		set_default_object(__FILE__);
	else
	{
		set("unit", "��");
		set("long", "����һ�Ѻ������˱�����������һ����Ʒ��\n");
		set("value", 50000);
		set("material", "steel");
		set("weapon_prop/courage", 30);

		set("wield_skill",([
			"sword" : 100,
		]));

		set("wield_ability",([
			"max_force" : 100,
			"combat_exp" : 100000,
                ]));

		set("wield_msg", "$N��ৡ���һ�����һ��$n�������С�\n");
		set("unwield_msg", "$N�����е�$n��������Ľ��ʡ�\n");
	}

	init_sword(60);
	setup();
}