// yayifu.c

#include <armor.h>

inherit CLOTH;

void create()
{
	set_name("衙役服", ({ "yayi cloth", "cloth" }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "这是一件衙役穿的官服。\n");
		set("unit", "件");
		set("value", 100);
		set("material", "cloth");
		set("armor_prop/armor", 1);
        }
	setup();
}