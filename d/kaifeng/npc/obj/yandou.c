// yandou.c

#include <ansi.h>

inherit ITEM;

void create()
{
        set_name(YEL"烟斗"NOR, ({ "yan dou" }) );
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "根");
                set("value",1000);
                set("material", "gold");
                set("long", "这是一根纯金的烟斗。\n");
        }
        setup();
}
