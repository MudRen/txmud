// sword.c
// by dicky

#include <ansi.h>
#include <weapon.h>
inherit SWORD;

void create()
{
	set_name(HIW"����"NOR, ({"sword"}) );
	set_weight(6000);
	if( clonep() )
		set_default_object(__FILE__);
	else
	{
		set("unit", "��");
		set("long", "����һ�ѿ����൱��ͨ�ĳ�����������С�̤ѩɽׯ���ı�ǡ�\n");
		set("value", 10);
		set("material", "steel");
		set("wield_msg", "$N��ৡ���һ�����һ��$n�������С�\n");
		set("unwield_msg", "$N�����е�$n��������Ľ��ʡ�\n");
	}

	init_sword(35);
	setup();
}