#include <weapon.h>

inherit STICK;

void create()
{
        set_name("木棍", ({ "wood stick", "stick" }) );
        set_weight(700);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("value", 100);
                set("material", "wood");
                set("long", 
"这是一把很轻木棍。\n");
        }
        init_stick(2);
        setup();
}
