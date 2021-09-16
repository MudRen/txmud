inherit ITEM;
#include <ansi.h>
void create()
{
        set_name(HIR"°µÉ±Áî"NOR, ({ "kill plate","plate" }) );
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "¿é");
                set("long", "ÕâÊÇÒ»¿éÏÊºìµÄÁîÅÆ¡£\n");
                //set("value", 1000);
        }
}

