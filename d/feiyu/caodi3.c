// Room: /wiz/louth/a/caodi3.c

inherit ROOM;

void create()
{
	set("short", "草地");
	set("long", @LONG
这是一片青青的草地，稀疏的长着几棵小树，偶尔传来几声
小鸟的鸣叫，使人感受到一种静谧的气氛。
LONG
);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"caodi2",
  "north" : __DIR__"caodi4",
]));
        set("objects", ([ /* sizeof() == 4 */
  __DIR__"npc/hufa1" : 1,
]));
	set("outdoors","feiyu");
	setup();
}

int valid_leave(object me, string dir)
{
	if(dir =="north" && me->query("class") != "rain" )
        {
                if(objectp(present("zhang suifeng", environment(me))) && !wizardp(me))
			return notify_fail("张随风道：那里不是你应该去的地方。\n");
	}
	return ::valid_leave(me, dir);
}
