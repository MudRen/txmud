// Room: /d/path4/cd07.c

inherit ROOM;

void create()
{
	set("short", "陟峭山路");
	set("long", @LONG
这是一间什麽也没有的空房间。

LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"cd06",
  "east" : __DIR__"cd08",
]));
	set("outdoors", "path4");
	setup();
	replace_program(ROOM);
}
