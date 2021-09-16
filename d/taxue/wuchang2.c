// wuchang2.c
// by dicky

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "练武场");
        set("long", @LONG
这里是个露天练武场，门口写着一块牌子（paizi）。好多人在这里辛苦的
练着，你走在场中，可是没有人回头看你一眼，都在聚精汇神的练着自己的功
夫，武场中间有一跟旗杆（qigan），看上非常的光滑，旗顶有一面晃子，上面
写着“踏雪”两个酋劲有力的大字。
LONG
        );

	set("outdoors","taxue");

        set("exits", ([
               "west" : __DIR__"wuchang1",
               "south" : __DIR__"liangong2",
        ]));

        set("item_desc", ([
           "qigan"  :  "这是一杆非常光滑的旗杆，晃子在上面迎风招展。\n",
	   "paizi" :
		HIY"
※※※※※※※※※※※※※※※※※※
※※※※　　　　　　　　　　※※※※
※※※※　                  ※※※※
※※※※     练  武  场     ※※※※
※※※※　                  ※※※※     
※※※※　　　　　　　　　　※※※※
※※※※※※※※※※※※※※※※※※\n\n"NOR,
	]));
		
        setup();
}

void init()
{
	add_action("do_climb", "climb");
	add_action("do_climb", "pa");
}

int do_climb(string arg)
{
	object me = this_player();
	int level, keecost;

	if (arg != "qigan" && arg != "qi")
		return notify_fail("你要爬什么？\n");

	if (me->is_busy() || me->is_fighting())
		return notify_fail("你正忙着哪！\n");

	level = me->query_skill("dodge", 1);
	keecost = level / 4 + random(level / 4);
        if (me->query("kee") <= keecost) {
		write("你太累了，先歇歇吧！\n");
		return 1;
	}
	if (level < 30) {
		write("你抱住旗杆，拼命往上爬，可以你爬了半天也怕不上去\n");
		return 1;
	}
	if (level > 100) {
		write("你抱住旗杆，一溜烟的爬上旗杆，引来旁边的阵阵博采之声。\n");
		return 1;
	}
	me->receive_damage("kee", keecost);
	write("你抱着旗杆，使劲地往上爬，费了好大的劲爬上旗杆，又溜了下来。\n");
	me->improve_skill("dodge", me->query("int"));
	return 1;
}
