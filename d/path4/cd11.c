// Room: /d/path4/cd11.c

inherit ROOM;

void create()
{
	set("short", "渡难坡");
	set("long", @LONG
这是一间什麽也没有的空房间。

LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "northwest" : __DIR__"cd10",
  "south" : __DIR__"cd12",
  "northeast" : __DIR__"tree01",
]));
	set("outdoors", "path4");
	setup();
	replace_program(ROOM);
}
