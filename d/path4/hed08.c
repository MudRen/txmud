// Room: /d/path4/hed08.c

inherit ROOM;

void create()
{
	set("short", "山林小路");
	set("long", @LONG
这是一间什麽也没有的空房间。

LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"mzhe",
  "northeast" : __DIR__"hed07",
]));
	set("outdoors", "path4");
	setup();
	replace_program(ROOM);
}
