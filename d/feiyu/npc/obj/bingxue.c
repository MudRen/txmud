#include <armor.h>
#include <ansi.h>
inherit CLOTH;

void create()
{
        set_name(HIW"冰雪寒衫"NOR, ({ "bingxue hanshan","cloth" }) );
        set_weight(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件");
                set("long", "这是一件薄薄的衣服。\n");
                set("value", 2000);
                set("material", "cloth");
                set("armor_prop/armor", 40);
        }
        setup();
}

