// huashan erhuang.c

#include <ansi.h>
#include <armor.h>
inherit CLOTH;

void create()
{
        set_name( HIY"鹅黄长裙"NOR, ({  "erhuang skirt","skirt" }) );
        set_weight(100);
        set("long", "这是一件华丽的鹅黄色丝质长衫，一看就知道是江南的贡丝制成的。\n");
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件");
                set("value", 1000);
                set("material", "cloth");
                set("armor_prop/armor", 30);
                set("armor_prop/dodge", -5);
		set("female_only", 1);
        }
        setup();
}
