#include <armor.h>
#include <ansi.h>
inherit CLOTH;

void create()
{
        set_name(HIW"吟风衣"NOR, ({ "yinfeng cloth","cloth" }) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件");
                set("long", "这件吟风衣是开封最有名的裁缝亲手做的。\n");
                set("value", 2500);
                set("material", "cloth");
                set("armor_prop/armor", 20);
        }
        setup();
}

