// Room: /d/jinghai/laofang.c

inherit ROOM;

void create()
{
	set("short", "牢房中");
	set("long", @LONG
这是一间什麽也没有的空房间。

LONG
	);

	setup();
	replace_program(ROOM);
}
