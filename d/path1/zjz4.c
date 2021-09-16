// Room: /d/path1/zjz4.c

inherit ROOM;

void create()
{
	set("short", "柏云坡");
	set("long", @LONG
白云飘荡，碧树蓝天，这里就是柏云坡了。你走到这里，不
知什么原故，心里突然感到一种不安，你四处看了看，却什么也
没有发现。西面一条小路通往枫晓亭，北面通向赵公口，再向南
穿过那片树林就到左家村了。

LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"py1",
  "north" : __DIR__"zjz3",
  "southeast" : __DIR__"zjz5",
]));
	set("outdoors", "path1");
	setup();
	replace_program(ROOM);
}
