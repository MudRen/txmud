#include <armor.h>
#include <ansi.h>
inherit CLOTH;

void create()
{
        set_name(HIB"霓裳艳影"NOR, ({ "nishang yanying","cloth" }) );
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件");
                set("long", "这件衣服是夜蝶的母亲为女儿做的，看起来很艳丽。\n");
                set("value", 1000);
                set("material", "cloth");
                set("armor_prop/personality", 8);
                set("armor_prop/armor", 20);
        }
        setup();
}
