#include <weapon.h>

inherit BLADE;

void create()
{
        set_name("木刀", ({ "wood blade", "blade" }) );
        set_weight(700);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("value", 100);
                set("material", "wood");
                set("long", 
"这是一把很轻木刀。\n");
        }
        init_blade(2);
        setup();
}
