// Room: /d/path4/hed05.c

inherit ROOM;

void create()
{
	set("short", "山林小路");
	set("long", @LONG
这是一间什麽也没有的空房间。

LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "southwest" : __DIR__"hed06",
  "northeast" : __DIR__"hed04",
]));
	set("outdoors", "path4");
	setup();
	replace_program(ROOM);
}
