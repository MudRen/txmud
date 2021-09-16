// waist.c
// by dicky

#include <armor.h>
#include <ansi.h> 
inherit WAIST;

void create()
{
	set_name(HIW"银扣腰带"NOR, ({ "yao dai", "yaodai","waist" }) );
	set_weight(500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
        set("unit","条");
		set("material", "steel");
		set("long", "这是一条银扣腰带，上面标有“踏雪山庄”的标记。\n");
		set("value", 5000);
		set("armor_prop/armor", 30);
	}
	setup();
}