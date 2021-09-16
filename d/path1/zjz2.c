// Room: /d/path1/zjz2.c

inherit ROOM;

void create()
{
	set("short", "林间小路");
	set("long", @LONG
一条崎岖不平的山间小路蜿蜒而去，两旁地上除了碎石什么
也没有。西边一座高山拔地而起，看上去十分险峻。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"zjz3",
  "north" : __DIR__"zjz1",
]));
	set("outdoors", "path1");
	setup();
	replace_program(ROOM);
}
