// shoe.c
// by dicky

#include <armor.h>
inherit BOOTS;
#include <ansi.h>

void create()
{
        set_name(GRN"绣花鞋"NOR, ({ "xiuhua xie", "shoe" }) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "双");
                set("long","这是一双绿色的布制绣花鞋。\n");
                set("value", 0);
                set("material", "cloth");
                set("armor_prop/dodge", 10);
              }
         setup();
}

