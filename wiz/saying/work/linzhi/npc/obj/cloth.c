//cloth.c  ╡ьеш
#include <armor.h>
inherit CLOTH;

void create()
{
        set_name("╡ьеш", ({ "zang pao","cloth","zp" }) );
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "╪Ч");
                set("material", "cloth");
                set("armor_prop/armor", 1);
        }
        setup();
}
