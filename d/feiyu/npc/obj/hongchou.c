#include <armor.h>
#include <ansi.h>
inherit CLOTH;

void create()
{
        set_name(HIR"红绸衣"NOR, ({ "zishou yi","cloth" }) );
        set_weight(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件");
                set("long", "这是一件面料很好的衣裳。\n");
                set("value", 500);
                set("material", "cloth");
                set("armor_prop/armor", 10);
        }
        setup();
}

