// wumu_stick.c

#include <weapon.h>

inherit STAFF;

void create()
{
	set_name("��ľ����", ({ "wumu gun", "gun" }) );
	set_weight(15000);
	if( clonep() )
		set_default_object(__FILE__);
	else
	{
		set("unit", "��");
		set("long", "����һͨ���ںڵĳ�����");
		set("value", 300);
		set("material", "wood");
		set("wield_msg", "$N��$n�������������С�\n");
		set("unwield_msg", "$N�ɿ������е�$n��\n");
	}

	init_staff(20);
	setup();
}