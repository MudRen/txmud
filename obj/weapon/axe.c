// axe.c

#include <weapon.h>

inherit AXE;

void create()
{
	set_name("����", ({ "axe" }) );
	set_weight(8000);
	if( clonep() )
		set_default_object(__FILE__);
	else
	{
		set("unit", "��");
		set("long", "����һ�����ص�������\n");
		set("material","iron");
		set("wield_msg", "$N�ó�һ��$n���������е���������\n");
		set("unwield_msg", "$N�������е�$n��\n");
	}
	init_axe(30);
	setup();
}