// ruanwei.c

#include <armor.h>

inherit ARMOR;

void create()
{
        set_name( "��⬼�",({ "ruanwei" }) );
        set_weight(4200);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("material", "copper");
                set("value",2000);
                set("armor_prop/armor", 30);
                set("armor_prop/dodge", -5);
        }
        setup();
}

