// Room: /u/w/wangs/b/kai174.c

inherit ROOM;

void create()
{
	set("short", "胡同");
	set("long", @LONG
这是一间什麽也没有的空房间。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 3 */
  "northeast" : __DIR__"kai176",
  "southwest" : __DIR__"kai171",
  "east" : __DIR__"kai175",
]));

	setup();
	replace_program(ROOM);
}
