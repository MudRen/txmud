inherit ITEM;
#include <ansi.h>
void create()
{
        set_name(HIB"必杀令"NOR, ({ "killer plate","plate" }) );
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "块");
                set("long", "这是一块杀手山庄的通用令牌。\n");
                //set("value", 1000);
        }
}
