#include <ansi.h>
#include <armor.h>
inherit NECK;

void create()
{
        set_name(HIW"项链"NOR, ({ "xiang lian" }) );
        set_weight(20);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "一串做工很精细的项链。\n");
                set("unit", "串");
                set("value", 50000);
                set("armor_prop/armor", 0);
                set("armor_prop/personality", 3);
                set("wear_msg", "$N轻轻地把一个$n戴在脖子上。\n");
                set("unwield_msg", "$N轻轻地把$n从脖子上除了下来。\n");
        }
        setup();
}
