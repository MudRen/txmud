#include <armor.h>
#include <ansi.h>
inherit CLOTH;

void create()
{
        set_name(WHT"貂皮大衣"NOR, ({ "diaopi dayi","cloth","dayi" }) );
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件");
                set("long", "这是一件皮色很好的大衣。\n");
                set("value", 10000);
                set("material", "cloth");
                set("armor_prop/personality", 4);
                set("armor_prop/armor", 10);
        }
        setup();
}
