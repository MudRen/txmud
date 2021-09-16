// rou7.c

#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", "内室");
	set("long", @LONG
这是一间简朴素雅的琴室，琴室里摆放着一把古朴的古
琴，琴的一端好象有烧过的痕迹，好象是传说中的焦尾古琴，
看见如此难得的古琴你也不禁想一展身手。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"rou6",
]));
        set("objects", ([ /* sizeof() == 4 */
  __DIR__"obj/se" : 1,
]));
	setup();
}

void init()
{
	add_action("do_move","move");
}

int do_move(string arg)
{
        object me = this_player(),ob;

	if(!ob = present("gu qin",this_object()))
		return 0;

	if( !ob->id(arg) && arg != "古琴")
		return notify_fail("你要挪什么？\n");

	message_vision("$N小心的挪了挪放在桌子上的那把古琴。\n只听见轰隆一声，墙壁的一边忽然开了一道门。\n",me);
	set("exits/enter",__DIR__"rou8");
	call_out("guanmen",8);
	return 1;
}

void guanmen()
{
	if(query("exits/enter"))
	{
		write("墙壁慢慢的合上了。\n");
		delete("exits/enter");
	}
}
