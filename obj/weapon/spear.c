// spear.c

#include <weapon.h>

inherit SPEAR;

void create()
{
	set_name( "��ǹ", ({ "spear" }) );
	set_weight(6000);
	if( clonep() )
		set_default_object(__FILE__);
	else
	{
		set("unit", "֦");
		set("long", "һ֦��ɫ���ɶ�ĳ�ǹ��\n");
		set("material", "iron");
		set("wield_msg", "$N����һ֦$n���������е���������\n");
		set("unwield_msg", "$N�������е�$n��\n");                
	}

	init_fork(20);
	setup();
}