//zang£­xue.c ²ØÑ¥¡£
#include <armor.h>
inherit BOOTS;

void create()
{
        set_name( "²ØÑ¥", ({ "zang xue","shoes","zx"}) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("material", "cloth");
                set("unit", "Ë«");
                set("value", 1000);
                set("armor_prop/armor", 1 );
        }
        setup();
}
