// Room: /d/huashan/tianti1.c

inherit ROOM;

void create()
{
	set("short", "天梯");
	set("long", @LONG
你爬到此处，只能双手扶崖，依壁而上了。侧目望去，无限
风光尽收眼底，别有一番“险中情”。
LONG
	);

	set("exits", ([ /* sizeof() == 2 */
  "northup" : __DIR__"tianti2",
  "southdown" : __DIR__"mingya",
]));
        set("outdoors", "huashan");
	setup();
}

void init()
{
	add_action("do_ba", "ba");
}

int do_ba(string arg)
{
	object me = this_player(), grass;

	if( (me->query("class") != "huashan")
	|| (me->query("quest/huashan_quest/name") != "草鞋")
	|| (me->query("quest/huashan_quest/num") >=2)
	|| (time() - me->query("quest_fail_time") < 120) )
		return notify_fail("你在这里仔细找了找，没发现哪些是「呼啦草」。\n");

	grass = new(__DIR__"obj/hl_grass");

	if(!grass->move(me))
	{
		destruct(grass);
		return notify_fail("你身上放不下再多的东西了。\n");
	}

	grass->set_master(me->query("id"));
	me->add("quest/huashan_quest/num",1);
	message_vision("$N仔细的辨认了一下，仔细的拔下了一小把「呼啦草」。\n",me);
	return 1;
}
