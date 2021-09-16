#include <weapon.h>

inherit SWORD;

void create()
{
        set_name("木剑", ({ "wood sword", "sword" }) );
        set_weight(700);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("value", 100);
                set("material", "wood");
                set("long", 
"这是一把很轻木剑。\n");
                set("wield_msg", "$N拿出一把$n，握在手中。\n");
                set("unequip_msg", "$N放下手中的$n。\n");
        }
        init_sword(2);
        setup();
}
