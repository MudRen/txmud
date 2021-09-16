// force-book.c
// by dicky

#include <ansi.h>
inherit ITEM;

void create()
{
set_name("内功心法", ({ "force book", "shu", "book" }));
        set_weight(50);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "本");
                set("long",
                        "这是小本内功心法。\n"
                        "这是一本书页发黄的书，里面密密麻麻的画了不少打坐吐呐的姿势。\n"
			"书角印有「踏雪山庄」的标志！\n");
                set("value", 500);
                set("material", "paper");
                set("skill", ([
			"party":        "taxue",
                        "name": "force",        // name of the skill
                        "exp_required": 100,     // minimum combat experience required
                        "gin_cost":     15,     // gin cost every time study this
                        "difficulty":   20,     // the base int to learn this skill
                        "max_skill":    50,     // the maximum level you can learn

                ]) );
        }
}