// Room: cufang1.c

inherit ROOM;

protected void refresh_table();

void create()
{
	set("short","厨房");
	set("long",@LONG
走到这里，你闻到一阵饭香，肚子也不由的开始咕咕叫了。
左手靠墙放着一张大木桌，上面摆着一个大笼屉，右手是一个大
水缸，要是渴了可以舀水(drink)喝。
LONG
);
	set("exits", ([ /* sizeof() == 2 */
	"east" : __DIR__"chufang2",
	"south":__DIR__"guodaow8",
]));

        set("objects", ([
		__DIR__"obj/table": 1,
        ]));

	setup();
	refresh_table();
}

protected void refresh_table()
{
	object *inv,zhuozi;
	int i = 6;

	if(!objectp(zhuozi = present("wood table", this_object())))
		return;

	call_out("refresh_table",300);

	if( sizeof( (inv = all_inventory(zhuozi)) ) )
		foreach( object one in inv )
			if(one->query("id") != "ai wo wo")
				destruct(one);
			else
				i--;

	if(i > 0)
	        while(i--)
	        {
			object food = new(__DIR__"obj/aiwowo");
			food->move(zhuozi);
		}
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
	me->add("water", 30);
	return 1;
}
