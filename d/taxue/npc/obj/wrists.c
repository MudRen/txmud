// wrists.c
// by dicky

#include <armor.h>
#include <ansi.h> 
inherit WRISTS;

void create()
{
	set_name(HIW"银钉护腕"NOR, ({"hu wan","huwan","wrists" }) );
	set_weight(600);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "双");
		set("value",4000);
		set("long", "这是一双银钉护腕，上面标有“踏雪山庄”的标记。\n");
		set("material", "steel");
		set("armor_prop/armor", 30);
	}
	setup();
}
