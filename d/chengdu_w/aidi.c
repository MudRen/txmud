// Room: /d/path5/aidi.c

inherit ROOM;

void create()
{
	set("short", "悬崖崖底");
	set("long", @LONG
这是一间什麽也没有的空房间。

LONG
	);

	setup();
	replace_program(ROOM);
}
