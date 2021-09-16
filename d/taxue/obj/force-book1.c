// force-book1.c
// by dicky

#include <ansi.h>
inherit ITEM;

void create()
{
set_name(HIB"调息手记"NOR, ({ "tiaoxi shouji", "shouji", "book" }));
        set_weight(50);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "本");
                set("long",
                        "这是一本调息手记。\n"
                        "书页有点发黄，里面密密麻麻的画了不少打坐吐呐的上乘方法。\n"
			"书角印有「踏雪山庄」的标志！");
    		set("value", 500);
                set("material", "paper");
                set("skill", ([
			"party":        "taxue",
                        "name": "force",
                        "exp_required": 100000, 
                        "gin_cost":     20, 
                        "difficulty":   25,
			"min_skill":    50,	
                        "max_skill":    101, 

                ]) );
        }
}