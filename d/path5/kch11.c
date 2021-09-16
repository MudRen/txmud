// Room: /d/path5/kch11.c

inherit ROOM;

void create()
{
	set("short", "五霸山顶");
	set("long", @LONG
你终于蹬上了山项。只见南方不远处一座更高的山峰呈现眼
前，隔山望去，嵯弊峨峨的山势，生得苍苍奕奕。一阵阵山风吹
过，你觉得有些累了。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "northdown" : __DIR__"kch10",
  "southdown" : __DIR__"kch12",
]));
        set("outdoors", "path5");
        set("cannot_build_home", 1);
        set("NORIDE", "依前面的地形，你徒步还能过去，它们是没戏了。");
	setup();
	replace_program(ROOM);
}
