// 樵夫，农民、小贩等用 by pian

#include <armor.h>
inherit CLOTH;

void create()
{
	set_name("粗布短衫", ({ "cloth" }) );
	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "件");
		set("material", "cloth");
		set("armor_prop/armor", 1);
	}
	setup();
}
