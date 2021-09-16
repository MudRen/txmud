// Room: /d/huashan/mingya.c

inherit ROOM;

void create()
{
	set("short", "明崖");
	set("long", @LONG
由此再往上，就是需依崖了。你走到这里，向下一看是万丈
深渊，不知归路。据说当年韩愈走到这里，吓得惊慌失措，于是
写下遗书，投下岭去。至今崖上还刻有“韩退之投书处”诸字。
LONG
	);

	set("exits", ([ /* sizeof() == 2 */
  "northup" : __DIR__"tianti1",
  "southdown" : __DIR__"yudao",
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
