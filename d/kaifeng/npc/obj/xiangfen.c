inherit ITEM;
#include <ansi.h>
void create()
{
        set_name(MAG"œ„∑€" NOR, ({ "xiang fen"}) );
        set_weight(10);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "∫–");
                set("long", "“ª∫–œ„≈Á≈Áµƒ∑€.\n");
                set("value", 1000);
        }
}

