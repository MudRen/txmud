// Room: /u/w/wangs/b/kai15.c

inherit ROOM;

void create()
{
	set("short", "柳中河畔");
	set("long", @LONG
这是一间什麽也没有的空房间。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "southwest" : __DIR__"kai14",
]));
        set("objects",([
        __DIR__"npc/songy": 1,
]));

	set("outdoors","kaifeng");
	setup();
	replace_program(ROOM);
}
