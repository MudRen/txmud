// Room: /d/path4/hed18.c

inherit ROOM;

void create()
{
	set("short", "听风岭");
	set("long", @LONG
这是一间什麽也没有的空房间。

LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "southwest" : __DIR__"hed19",
  "northeast" : __DIR__"hed17",
]));
	set("outdoors", "path4");
	setup();
	replace_program(ROOM);
}
