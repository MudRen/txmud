// Room: /d/jinghai/kongdi.c

inherit ROOM;

void create()
{
	set("short", "海滩上");
	set("long", @LONG
这是一间什麽也没有的空房间。

LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"houmen",
]));
        set("outdoors","jinghai");

	setup();
	replace_program(ROOM);
}
