// biaoji.c
// by dicky

#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(HIW"兽皮"NOR, ({ "shou pi", "shou pi" }) );
	set("long", "这是一张野兽的皮，有了他就可以去领取奖励。\n");
        set_weight(2);
	set("no_drop", 1);
	set("no_give",1);
        set("value", 20);
	set("no_put",1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "张");
        }
        setup();
}

