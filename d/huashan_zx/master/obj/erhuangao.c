// erhuangao.c

#include <ansi.h>
#include <armor.h>
inherit CLOTH;
void create()
{
        set_name( HIM"紫云笼翠"NOR, ({  "erhuang ao" }) );
        set_weight(100);
        set("long", HIG"一件华丽的丝质长衫，据说是用银线夹在丝里织成的，有提神醒脑的功效。\n"NOR);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件");
                set("value", 6000);
                set("material", "cloth");
                set("armor_prop/armor", 2);
                set("armor_prop/dodge", -30);
                set("armor_prop/literate",30);
        }
        setup();
}
