// skirt.c
// by dicky

#include <ansi.h>
#include <armor.h>
inherit CLOTH;

void create()
{
        set_name(MAG"绿衫长裙"NOR, ({ "lvshan changqun", "changqun", "skirt" }) );
        set_weight(1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("long","这是一条绿色的长裙。\n");
                set("unit", "条");
                set("value", 0);
                set("material", "cloth");
                set("armor_prop/armor", 20);
                

        }    
        setup();
}
