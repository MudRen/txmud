// Room: /d/tangmen/chufang.c

inherit ROOM;

protected void refresh_table()
{
	object *inv,zhuozi;
	int i = 15;

	if(!objectp(zhuozi = present("wood table", this_object())))
		return;

	call_out("refresh_table",300);

	if( sizeof( (inv = all_inventory(zhuozi)) ) )
		foreach( object one in inv )
			if(!one->is_food())
			{
				if(one->is_character())
					one->move(this_object());
				else
					destruct(one);
			}
			else
				i--;

	if(i > 0)
	        while(i--)
	        {
			object food = new(FOOD_DIR"chicken_leg");
			food->move(zhuozi);
		}
}

void create()
{
	set("short", "厨房");
	set("long", @LONG
这里就是厨房，这里最显眼的就是一口巨大的水缸。房子中
间的餐桌上放着各种吃食，几个厨子在走来走去的忙和着，渴了
就随便从水缸里舀(drink)点水喝。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"gd4",
]));

        set("objects", ([
		__DIR__"obj/table": 1,
]));

	setup();
	refresh_table();
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
	if( (me->query("class") != "tangmen")
	&& (random(10) < 3) )
		me->apply_condition("mabi", 10);
	return 1;
}
