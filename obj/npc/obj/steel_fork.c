// steel_fork.c

#include <weapon.h>

inherit FORK;

void create()
{
	set_name("��ɸֲ�", ({ "steel fork" }) );
	set_weight(30000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value", 1000);
		set("material", "steel");
	}
	init_fork(30);

	setup();
}
