// hands.c
// by dicky

#include <armor.h>
#include <ansi.h> 
inherit HANDS;
void create()
{
	set_name(HIW"银丝手套"NOR, ({ "shou tao","shoutao","hand" }) );
	set_weight(600);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit","副");
		set("material", "steel");
		set("long", "这是一副银丝手套，上面标有“踏雪山庄”的标记。\n");
		set("value", 4000);
		set("armor_prop/armor", 30);
	}
	setup();
}