// Room: /d/datong/zhai2.c

inherit ROOM;

void create()
{
	set("short", "内厅");
	set("long", @LONG
这是一间什麽也没有的空房间。

LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "northeast" : __DIR__"zhai3",
  "south" : __DIR__"sizhai2",
]));

	setup();
	replace_program(ROOM);
}
