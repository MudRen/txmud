#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create()
{
        set_name(HIW"白衫"NOR, ({ "cloth" }) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件");
                set("long", "这是绯雨阁四杀手专门穿的衣服。\n");
                set("value", 3000);
                set("material", "cloth");
                set("armor_prop/armor", 50);
        }
        setup();
}
