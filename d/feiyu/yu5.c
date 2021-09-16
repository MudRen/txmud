// Room: /u/w/wangs/a/yu5.c

inherit __DIR__"patroling";

void create()
{
	set("short", "绯雨阁前院");
	set("long", @LONG
这里是绯雨阁的前院，相当宽敞。院中种满了各种花草，
清风吹来，香气袭人。东西两旁各有一条小路穿过月亮门通
向院后。
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"yu21",
  "north" : __DIR__"yu2",
  "west" : __DIR__"yu15",
  "east" : __DIR__"yu6",
]));
        set("objects", ([
        __DIR__"npc/zong2": 1,
]) );

	set("outdoors","feiyu");
	setup();
}

int valid_leave(object me, string dir)
{
	object ob;

        if (dir =="south"
	&& (me->query("gender") == "男性")
	&& !wizardp(me) )
        {
		if (objectp(ob = present("lv ling", this_object())) &&  living(ob))
			return notify_fail("绿绫喝道：站住，绯雨阁禁止男性进入！\n");
	}
	return ::valid_leave(me, dir);
}

