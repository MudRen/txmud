//cassock.c  ôÂôÄ¡£
#include <armor.h>
inherit CLOTH;
void create()
{
        set_name("×ÏºìôÂôÄ", ({ "purple cassock","cassock",}) );
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "¼ş");
                set("material", "cloth");
                set("armor_prop/armor", 2);
        }
        setup();
}
