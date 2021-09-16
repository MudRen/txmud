// Room: /wiz/louth/a/shanlu9.c

inherit ROOM;

void create()
{
	set("short", "山路");
	set("long", @LONG
你走在一条蜿蜒的小径，小径的两旁是半个人高的杂草，
你可以感受到清凉的微风从两侧吹来。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"yu1",
  "north" : __DIR__"shanlu8",
]));
        set("objects", ([ /* sizeof() == 4 */
  __DIR__"npc/hufa2" : 1,
]));
	setup();
}

int valid_leave(object me, string dir)
{
	object ob;

        if(dir =="east"
	&& (me->query("gender") == "男性")
	&& !wizardp(me) )
        {
		if(objectp(ob = present("zhang piaoxue", this_object())) && living(ob))
                return notify_fail("张飘雪大喝一声：站住，绯雨阁禁止男性进入！\n");
        }
	return ::valid_leave(me, dir);
}

