// Room: /d/jinghai/xuanya1.c

inherit ROOM;

void create()
{
	set("short", "悬崖尽头");
	set("long", @LONG
这是一间什麽也没有的空房间。

LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"xuanya",
]));
        set("outdoors","jinghai");

	setup();
	replace_program(ROOM);
}
