// rope.c

#include <weapon.h>

inherit WHIP;

void create()
{
	set_name( "Ƥ��", ({ "whip" }) );
	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else
	{
		set("unit", "��");
		set("long", "����һ�������൱��ͨ��Ƥ�ޡ�\n");
		set("material", "skin");
		set("wield_msg", "$N����������һ��$n�������С�\n");
		set("unwield_msg", "$N�����е�$n�������䡣\n");
	}

	init_whip(10);
	setup();
}