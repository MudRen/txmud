// Room: /d/path4/dw07.c

inherit ROOM;

void create()
{
	set("short", "原始森林边");
	set("long", @LONG
这是一间什麽也没有的空房间。

LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "southeast" : __DIR__"dw06",
]));
	set("outdoors", "path4");
	setup();
	replace_program(ROOM);
}
