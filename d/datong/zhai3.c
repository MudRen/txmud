// Room: /d/datong/zhai3.c

inherit ROOM;

void create()
{
	set("short", "后院");
	set("long", @LONG
这是一间什麽也没有的空房间。

LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "southwest" : __DIR__"zhai2",
]));

	set("objects",([
	__DIR__"npc/xiaocui" : 1,
]));
	setup();
	replace_program(ROOM);
}
