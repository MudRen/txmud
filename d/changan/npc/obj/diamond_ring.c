// diamond_ring.c

#include <ansi.h>
#include <armor.h>

inherit FINGER;

void create()
{
       set_name( HIW "×êÊ¯½äÖ¸" NOR, ({ "diamond ring", "ring" }) );
       set_weight(100);
       if( clonep() )
              set_default_object(__FILE__);
       else {
              set("unit", "¸ö");
              set("value", 100000);
              set("material", "gold");
              set("armor_type", TYPE_FINGER);
              set("armor_prop/armor", 5);
              set("armor_prop/dodge", 2);
       }
}
