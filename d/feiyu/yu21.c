// Room: /u/w/wangs/a/yu21.c

inherit ROOM;

void create()
{
	set("short", "绯雨阁大厅");
	set("long", @LONG
这是绯雨阁的大厅，内部摆设极尽豪华，当中一张黑色
檀木条案，上面陈放着精美的花瓶和一些珍贵的瓷器，四壁
挂满名家的字画。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"yu22",
  "north" : __DIR__"yu5",
]));
        set("objects", ([
        __DIR__"npc/zong1": 1,
]) );
	set("valid_startroom", 1);
	set(SAFE_ENV,1);
	setup();

	load_board("board_feiyu");
}

int valid_leave(object me, string dir)
{
	object ob;

        if (dir =="south")
	{
		if( (me->query("class") != "rain")
		&& !wizardp(me)
		&& objectp(ob = present("qing wu", this_object())) && living(ob) )
			return notify_fail("青妩娇喝道：站住，那里不是你去的地方！\n");

                if(sizeof(filter_array(all_inventory(me),(: $1->is_character() :))))
                        return notify_fail("青妩喝道：站住，鬼鬼祟祟的想带什么人进去！\n");
	}
	return ::valid_leave(me, dir);
}
