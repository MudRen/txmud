// cloth.c
// by dicky

#include <armor.h>
#include <ansi.h>
inherit BOOTS;

void create()
{
        set_name(HIY"九耳麻鞋"NOR, ({ "jiuer maxie","maxie","shoes" }) );
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "双");
		set("long", "这是一双九耳麻鞋，上面标有“踏雪山庄”的标记。\n");
                set("material", "cloth");
		set("value", 5000);
		set("armor_prop/dodge", 10);
		set("armor_prop/armor", 30);
        }
        setup();
}
