// fengyuesword.c

#include <weapon.h>
#include <ansi.h>
inherit SWORD;
inherit F_CONTROL;

void create()
{
	set_name(HIW"���½�"NOR, ({ "fengyue sword","sword" }) );
	set_weight(800);

	if( clonep() )
		set_default_object(__FILE__);
	else
	{
		set("unit", "��");
		set("long", "����һ�����������˶�����õ��ı���.\n");
		set("value", 40000);
		set("material", "steel");
		set("valid_number",1);

		set("wield_msg", "$N�ӽ�������һ��ѩ�׵�$n�������С�\n");
		set("unwield_msg", "$N�����е�$n��ؽ����С�\n");

		set("wield_skill",([
			"sword" : 150,
		]));
		set("wield_ability",([
			"combat_exp" : 600000,
		]));
	}

	init_sword(80);
	setup();
}
