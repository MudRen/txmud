#include <armor.h>
#include <ansi.h>
inherit CLOTH;

void create()
{
        set_name(MAG"紫色小褂"NOR, ({ "xiao gua"}) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件");
                set("long", "这是件质地很好的小褂。\n");
                set("value", 8000);
                set("material", "cloth");
                set("armor_prop/personality", 5);
                set("armor_prop/armor", 25);
        }
        setup();
}
