// Room: /d/huashan/dongkou.c

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "洞口");
	set("long", @LONG
你站在洞口，背后是湍急的瀑布。借着外面的微光，你看到
湿露露的地面像人工开凿过石路通往西面。你按捺不住好奇的心
情，想进去看个究竟。“隆隆”的瀑布声阵得你其它的声音什么
也听不见。脚下的鹅卵石被水冲刷的非常光滑，看样子要从这里
跳出去不是一件容易的事情。
LONG
	);

	set("exits", ([ /* sizeof() == 2 */
          "west" : __DIR__"shitai",
]));

	setup();
}

void init()
{
	add_action("do_enter", ({"jump", "tiao"}));
}
        
int do_enter(string arg)
{
	object me = this_player();

        if( arg != "out" )
		return 0;

	message_vision(HIY"$N跑了几步，一提气向瀑布外跃了出去。\n"NOR, this_player());

	if( me->move(__DIR__"sl_dong") )
		tell_room(environment(me), me->name() + "从瀑布边跌跌撞撞的走了过来。\n",({me}));
        return 1;
}
