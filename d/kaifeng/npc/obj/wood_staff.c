#include <weapon.h>

inherit STAFF;

void create()
{
        set_name("木杖", ({ "wood staff", "staff" }) );
        set_weight(700);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("value", 100);
                set("material", "wood");
                set("long", 
"这是一把很轻木杖。\n");
        }
        init_staff(2);
        setup();
}
