// Room: /d/hangzhou/bigroad.c

inherit ROOM;

void create()
{
	set("short", "官道");
	set("long", @LONG
你正走在杭州府的官道上，这里向南就可以到达杭州府的南
大门，可以算得上是杭州的门面，因此格外的干净。街道的东面
是杭州商栈。
LONG
	);
	set("outdoors", "hangzhou");
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"southdoor",
  "east" : __DIR__"business",
  "north" : __DIR__"guotaie3",
]));


        set("objects",([
        NPC_DIR"xunpu" : 2,
]));

	setup();
	replace_program(ROOM);
}
