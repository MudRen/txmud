// wuchang1.c
// by dicky

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "练武场");
        set("long", @LONG
这里是个露天练武场，门口写着一块牌子（paizi）。好多人在这里辛苦的
练着，你走在场中，可是没有人回头看你一眼，都在聚精汇神的练着自己的功
夫。武场中央有一棵老松树(tree)，显得十分的粗壮，树上的树叶非常茂密，
有几只不知名的小鸟在其中窜来窜去。
LONG
        );

	set("outdoors","taxue");

        set("exits", ([              
               "east" : __DIR__"wuchang2",
               "north" : __DIR__"shilu5",
               "south" : __DIR__"liangong",
        ]));

        set("item_desc", ([
          "tree" : "一棵大松树，枝叶茂密，看不清上面的情况。\n",
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
	add_action("do_shake", "yao");
	add_action("do_shake", "huang");
}

int do_shake(string arg)
{
	object me = this_player();
	int level, keecost;

	if (arg != "tree" && arg != "shu" && arg != "dashu")
		return notify_fail("你要摇什么？\n");

	if (me->is_busy() || me->is_fighting())
		return notify_fail("你正忙着哪！\n");

	level = me->query_skill("parry", 1);
	keecost = level / 4 + random(level / 4);
        if (me->query("kee") <= keecost) {
		write("你太累了，先歇歇吧！\n");
		return 1;
	}
	if (level < 30) {
		write("你使劲地摇晃着大树，大树却纹丝不动，你不禁想到那句“蚍蜉撼树”的成语来。\n");
		return 1;
	}
	if (level > 100) {
		write("你使劲地摇晃着大树，把树上的叶子都摇得落到几丈开外去了。\n");
		return 1;
	}
	me->receive_damage("kee", keecost);
	if (!random(5))
		message_vision("$N使劲地摇着大树，从树上掉下几个松子来，砸向$N的头脸，$N赶忙伸臂架开。\n", me);
	else
		write("你使劲地摇着大树，从树上掉下几个松子来，砸向你的头脸，你赶忙伸臂架开。\n");
	me->improve_skill("parry", me->query("int"));
	return 1;
}
