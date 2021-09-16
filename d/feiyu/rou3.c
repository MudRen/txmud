// rou3.c

#include <ansi.h>;
inherit ROOM;

void create ()
{
	set("short", "翠竹斋");
	set ("long", @LONG
幽幽翠竹，片片随风，虽然外面是白玉雕栏，里面却完全是
另一种情调。两旁是翠绿色玉石柱子，仔细看去，左边的柱子中
间非常光华，好象经常被人触摸。
LONG);

	set("item_desc",([
	"柱子" : "你发现柱子上好象有一个地方陷了下去，好像经常被人按动。\n",
]));

	set("exits", ([ /* sizeof() == 1 */
	"out" : __DIR__"rou2",
]));

	set(SAFE_ENV,1);

	setup();
}

void init()
{
	add_action("do_an","an");
}

int do_an(string arg)
{
	object me = this_player();

	if(arg != "柱子"&& arg != "zhuzi")
		return 0;

	message_vision("地下突然裂开一个洞，只见$N掉了下去。\n",me);
	tell_room(__DIR__"rou4",sprintf("%s从上面掉了下来。\n",me->name()));
	me->move(__DIR__"rou4");
	return 1;
}
