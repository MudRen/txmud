#include <armor.h>
#include <ansi.h>
inherit CLOTH;

void create()
{
        set_name(YEL"羊皮小衫"NOR, ({ "yangpi xiaoshan","cloth","xiaoshan" }) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件");
                set("long", "这是一件皮色很好的大衣。\n");
                set("value", 5000);
                set("material", "cloth");
                set("armor_prop/personality", 1);
                set("armor_prop/armor", 6);
        }
        setup();
}
