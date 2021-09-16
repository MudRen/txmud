// Room: /d/path1/py8.c

inherit ROOM;

void create()
{
	set("short", "土路");
	set("long", @LONG
这是一条泥宁的黄土小路，路上到处是马匹的粪便，过往的
车辆压得路面高低不平。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"py9",
  "east" : __DIR__"py7",
]));
	set("outdoors", "path1");
	setup();
	replace_program(ROOM);
}
