// Room: /d/path4/hed12.c

inherit ROOM;

void create()
{
	set("short", "山边小路");
	set("long", @LONG
这是一间什麽也没有的空房间。

LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"hed13",
  "northeast" : __DIR__"hed11",
]));
	set("outdoors", "path4");
	setup();
	replace_program(ROOM);
}
