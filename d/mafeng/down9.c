// Room: /d/mafeng/down9.c

inherit ROOM;

protected void send_msg()
{
	object room;
	string file;

	if( objectp(room = find_object(file=__DIR__"control"))
	|| objectp(room = load_object(file)) )
		room->check_rooms();
}

void create()
{
	set("short", "石室");
	set("long", @LONG
这是一间宽大的石室，四周都是用打磨的非常平滑的青石砌
成的，中间是一个石柱，环绕石柱插着四根大火把，将整个石室
照的灯火通明。右面的墙上还雕刻着一个虎头。
LONG
	);

	set("item_desc", ([
	"虎头" : "一个用石头雕刻的栩栩如生的虎头，表面非常的光滑。\n",
]));

	set("exits", ([ /* sizeof() == 1 */
  "northwest" : __DIR__"down8",
]));

	setup();
}

void reset() { }

void init()
{
	add_action("do_push", "push");
}

int do_push(string arg)
{
	object me;

	if(arg != "虎头")
		return notify_fail("你要推什么？\n");

	me = this_player();

	message_vision("$N用力推了一下虎头，虎头向边上移动了一下。
一阵声响过后，突然脚下的石板向两旁分开，$N掉了下去。\n", me);

	me->move(__DIR__"out1");

	if(find_call_out("send_msg") == -1)
		call_out("send_msg", 3);
	return 1;
}

#include "kill.h";