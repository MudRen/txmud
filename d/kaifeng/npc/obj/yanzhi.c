inherit ITEM;
#include <ansi.h>
void create()
{
        set_name(RED"ÎŸ÷¨" NOR, ({ "yan zhi"}) );
        set_weight(30);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "∫–");
                set("long", "“ª∫–…œµ»ÎŸ÷¨.\n");
                set("value", 50000);
        }
}

