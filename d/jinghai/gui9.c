// Room: /d/jinghai/gui9.c

inherit ROOM;

void create()
{
	set("short", "后山大码头");
	set("long", @LONG
这是一间什麽也没有的空房间。

LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "northdown" : __DIR__"gui7",
  "east" : __DIR__"gui10",
  "west" : __DIR__"gui11",
]));

	setup();
	replace_program(ROOM);
}
