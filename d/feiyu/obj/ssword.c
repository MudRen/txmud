#include <weapon.h>
inherit SWORD;

void create()
{
        set_name("短剑", ({ "short sword","sword" }) );
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", "这是一把练习用的短剑。\n");
                set("value", 100);
                set("material", "iron");
        }
        init_sword(10);
        setup();
}

