// Room: /u/w/wangs/b/kai24.c

inherit ROOM;

void create()
{
	set("short", "木匠铺");
	set("long", @LONG
这是一间什麽也没有的空房间。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"kai23",
]));

        set("objects",([
        __DIR__"npc/mujiang" : 1,
]));

	setup();
	replace_program(ROOM);
}
