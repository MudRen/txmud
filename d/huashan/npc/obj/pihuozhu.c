#include <ansi.h>
#include <armor.h>
inherit CLOTH;

void create()
{
	set_name(HIR"辟火珠"NOR, ({ "pihuo zhu","zhu" }) );
	if ( clonep() )
              set_default_object(__FILE__);
     	else {
     	set("long",WHT"这是一只辟火珠，是千年血蟾的内丹。对火和毒有天然的抗力。\n"NOR);
	set_weight(3000);
	
		set("unit", "颗");
		set("material", "cloth");
		set("armor_prop/armor", 100);
	}
	setup();
}
