//teng-armor.c Î÷²ØÓÃÌÙ¼×¡£
#include <armor.h>
inherit ARMOR;
void create()
{
        set_name("ÌÙ¼×", ({"teng armor", "armor" }) );
        set_weight(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "¼þ");
                set("material", "wood");
                set("value", 3000);
                set("armor_prop/armor", 20);
                set("armor_prop/dodge", -1);
        }
        setup();
}
