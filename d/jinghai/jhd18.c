// Room: /d/jinghai/jhd18.c

inherit ROOM;

void create()
{
	set("short", "牢房");
	set("long", @LONG
这是一间什麽也没有的空房间。

LONG
	);
	set("exits", ([ /* sizeof() == 1 */
]));

	setup();
	replace_program(ROOM);
}
