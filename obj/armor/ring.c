// ring.c

#include <armor.h>

inherit FINGER;

void create()
{
       set_name( "ָ��", ({ "ring" }) );
       set_weight(400);
       if( clonep() )
              set_default_object(__FILE__);
       else {
              set("unit", "��");
              set("value", 200);
              set("material", "iron");
              set("armor_prop/armor", 1);
              set("armor_prop/dodge", 1);
       }
}