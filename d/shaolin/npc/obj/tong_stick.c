// tong_stick.c

#include <weapon.h>

inherit STICK;

void create()
{
	set_name("ͭ��", ({ "tong gun", "gun" }) );
	set_weight(15000);
	if( clonep() )
		set_default_object(__FILE__);
	else
	{
		set("unit", "��");
		set("long", "����һ���þ�����ͭ��");
		set("value", 300);
		set("material", "wood");
		set("wield_msg", "$N��$n�������������С�\n");
		set("unwield_msg", "$N�ɿ������е�$n��\n");
	}

	init_stick(20);
	setup();
}