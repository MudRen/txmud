#include <armor.h>
#include <ansi.h>
inherit HEAD;

void create()
{
        set_name(WHT"瓜皮帽"NOR, ({ "guapi mao" }) );
        set_weight(400);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "顶");
                set("long", "这是顶质地很好的瓜皮帽。\n");
                set("value", 500);
                set("material", "cloth");
                set("armor_prop/armor", 10);
        }
        setup();
}

