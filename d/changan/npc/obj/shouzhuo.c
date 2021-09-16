// shouzhuo.c

#include <ansi.h>

#include <armor.h>
inherit WRISTS;

void create()
{
    set_name(HIG "翡翠手镯" NOR, ({"cui shouzhuo","shouzhuo","cui"}) );
     set_weight(50);
     if ( clonep() )
              set_default_object(__FILE__);
     else {
            set("long", "一支碧绿的翡翠手镯。\n");
            set("unit", "支");
            set("value", 20000);
            set("material","glass");
            set("armor_prop/armor",2);
            set("armor_prop/dodge", 2);
            set("wear_msg", "$N把$n带在手上。\n");
     }
     setup();
}