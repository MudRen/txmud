// Room: /d/jinghai/gui10.c

inherit ROOM;

void create()
{
	set("short", "东码头");
	set("long", @LONG
这是一间什麽也没有的空房间。

LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"gui9",
]));

	setup();
	replace_program(ROOM);
}
