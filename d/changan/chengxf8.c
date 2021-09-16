// Room: chengxf8.c

inherit ROOM;

void create()
{
        set("short", "厨房");
	set("long", @LONG
这里是长安丞相府的厨房，一进门你就闻了一阵香味，这里
的厨师，都是从长安大酒楼挑来的，西边有一大排火灶，两个小
厮在拉着风箱，“呼呼”有声。东边放着一个大水缸。
LONG
	);

	set("all_water",200);

        set("exits", ([
  "east" : __DIR__"chengxf6",
]));

	set("objects",([
	__DIR__"npc/chu_zi" : 1,
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

	if(query("all_water") <= 0)
		return notify_fail("水缸里一滴水也没有了。\n");

	if( (int)me->query("water") >= (int)me->max_water_capacity() )
                return notify_fail("你已经再也喝不下一滴水了。\n");

	message_vision("$N在水缸边用杯子舀起水喝了几口。\n", me);
	me->add("water", 20);
	add("all_water",-1);
	if(query("all_water") <= 0)
		return notify_fail("水缸已经被你给喝干了。\n");
	return 1;
}
