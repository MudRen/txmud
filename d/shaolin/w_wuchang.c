// Room: /d/shaolin/w_wuchang.c

inherit ROOM;

void create()
{
	set("short", "练武场");
	set("long", @LONG
这是一间什麽也没有的空房间。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"lroad2",
]));
	set("no_clean_up", 0);
	set("outdoors","shaolin");
	setup();
	replace_program(ROOM);
}
