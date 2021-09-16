// Room: /d/path1/zjz9.c

inherit ROOM;

void create()
{
	set("short", "小土路");
	set("long", @LONG
一条小路向东通去，不远处就是左家村。路面高低不平，两
侧都是庄稼地。西面是一片树林，林中一条小路不知通向何方。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"zjz8",
  "east" : "/d/zuojiacun/lu1",
]));
	set("outdoors", "path1");
	setup();
	replace_program(ROOM);
}
