// Room: /d/heifeng/first.c

inherit ROOM;

void create()
{
	set("short", "大寨主居室");
	set("long", @LONG
这是一间什麽也没有的空房间。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"xiaolu2",
]));

	setup();
	replace_program(ROOM);
}
