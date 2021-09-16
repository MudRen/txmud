// ruby_ring.c

#include <ansi.h>

inherit EQUIP;

void create()
{
       set_name(HIR "ºì±¦Ê¯"+ NOR "½äÖ¸", ({ "ruby ring", "ring" }) );
       set_weight(100);
       if( clonep() )
              set_default_object(__FILE__);
       else {
              set("unit", "¸ö");
              set("value", 8000);
              set("material", "cloth");
              set("armor_type", "finger");
              set("armor_prop/armor", 10);
              set("armor_prop/dodge", 5);
       }
}
