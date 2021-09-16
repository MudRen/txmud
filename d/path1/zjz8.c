// Room: /d/path1/zjz8.c

inherit ROOM;

void create()
{
	set("short", "林间小路");
	set("long", @LONG
这是一条林间小路，飞鸟在林间叽叽喳喳地叫着。风一吹来，
只感到湿气重重，树叶顺着风向缓缓飘落。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"zjz9",
  "northwest" : __DIR__"zjz7",
]));
	set("outdoors", "path1");
	setup();
	replace_program(ROOM);
}
