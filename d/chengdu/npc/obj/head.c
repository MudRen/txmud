// head.c

#include <armor.h>

inherit HEAD;

void create()
{
	set_name("����ͷ��", ({ "liusu tou jin" }) );
	set_weight(800);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit","��");
		set("material", "cloth");
		set("value", 800);
		set("armor_prop/armor", 15);
	}
	setup();
}