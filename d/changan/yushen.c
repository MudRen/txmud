// Room: /d/changan/yushen.c

inherit ROOM;

void create()
{
	set("short", "狱神庙");
	set("long", @LONG
这是一间什麽也没有的空房间。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"whroad1",
]));

	setup();
	replace_program(ROOM);
}
