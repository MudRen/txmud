// head.c
// by dicky

#include <armor.h>
#include <ansi.h> 
inherit HEAD;

void create()
{
	set_name(HIW"银丝头巾"NOR, ({ "tou jing", "toujing","head" }) );
	set_weight(800);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit","条");
		set("material", "steel");
		set("long", "这是一条银丝头巾，上面标有“踏雪山庄”的标记。\n");
		set("value", 5000);
		set("armor_prop/armor", 30);
		set("armor_prop/dodge", -2);
	}
	setup();
}