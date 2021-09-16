// Room: /d/shaolin/zhaitang.c

inherit ROOM;

void create()
{
	set("short", "斋堂");
	set("long", @LONG
这里是少林寺的斋堂，按佛教的习惯过午不食，也就是午时
之前，酉时之后才可以吃东西的，少林寺是一天二餐，其它的时
候是不允许生火的。所以早晚时这里特别忙碌，伙头僧们忙着生
火，劈柴，虽然是素斋，但仍可以闻到阵阵的清香。靠墙放着一
口大水缸，你要是渴了可以在这舀(drink)水喝。从这里向南是西
跨院。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"w_court",
]));

	set("objects", ([
	__DIR__"npc/shaofan_seng" : 1,
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
