// stick.c

#include <weapon.h>

inherit STICK;

void create()
{
	set_name("ľ��", ({ "stick" }) );
	set_weight(5000);
	if( clonep() )
		set_default_object(__FILE__);
	else
	{
		set("unit", "��");
		set("long", "����һ�ѿ����൱��ͨ��ľ��");
		set("material", "wood");
		set("wield_msg", "$N��$n�������������С�\n");
		set("unwield_msg", "$N�ɿ������е�$n��\n");
	}

	init_stick(10);
	setup();
}