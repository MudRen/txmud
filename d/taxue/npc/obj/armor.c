// armor.c
// by dicky

#include <ansi.h> 
#include <armor.h>
inherit CLOTH;

void create()
{
        set_name(HIW"银亮护胸"NOR, ({ "yinliang huxiong","huxiong","armor"}) );
        set_weight(600);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件");
		set("long", "这是一件银亮护胸，上面标有“踏雪山庄”的标记。\n");
                set("material", "steel");
                set("value", 5000);
                set("armor_prop/armor", 60);
        }
        setup();
}

