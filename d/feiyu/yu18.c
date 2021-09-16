// Room: /u/w/wangs/a/yu18.c

inherit ROOM;

void create()
{
	set("short", "厨房");
	set("long", @LONG
这里是绯雨阁的厨房，可能不是用餐的时间吧，所以厨
房里一个人都没有，如果你肚子饿了，就只好自己拿些吃的
充充饥了。靠墙放着一口大水缸，你要是渴了可以在这舀
(drink)水喝。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"yu8",
  "east" : __DIR__"yu17",
]));
        set("objects", ([ /* sizeof() == 4 */
  __DIR__"obj/jitui" : 10,
  __DIR__"obj/jibozi" : 10,
  __DIR__"obj/jichi" : 10,
]));

	setup();
}

void init()
{
	add_action("do_drink", "drink");
}

int do_drink(string arg)
{
	object me = this_player();

	if( (int)me->query("water") >= (int)me->max_water_capacity() )
		return notify_fail("你已经再也喝不下一滴水了。\n");

	message_vision("$N在水缸边用杯子舀起水喝了几口。\n", me);
	me->add("water", 20);
	return 1;
}
