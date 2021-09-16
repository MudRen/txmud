// sword.c
// by dicky

#include <ansi.h>
#include <weapon.h>
inherit SWORD;

void create()
{
	set_name(HIW"��֮��"NOR, ({ "wind of sword","sword"}) );
	set_weight(100);
	set("disappear",1);
	set("no_sell",1);
	if( clonep() )
		set_default_object(__FILE__);
	else
	{
		set("unit", "��");
		set("long", "����һ�ѿ����൱��ͨ�ĳ�����������С�̤ѩɽׯ���ı�ǡ�\n");
		set("material", "steel");
		set("wield_msg", "$N��ৡ���һ�����һ��$n�������С�\n");
		set("unwield_msg", "$N�����е�$n��������Ľ��ʡ�\n");
	}

	init_sword(40);
	setup();
}
