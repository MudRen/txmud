// Room: /d/path5/kch12.c

inherit ROOM;

void create()
{
	set("short", "崎岖山路");
	set("long", @LONG
这是一条崎岖的山路，你走到这里，不觉得有些累了。不时
有一些碎石从山上滑落，你不得不万分小心。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "southeast" : __DIR__"kch13",
  "northup" : __DIR__"kch11",
]));
        set("outdoors", "path5");
        set("cannot_build_home", 1);
        set("NORIDE", "依前面的地形，你徒步还能过去，它们是没戏了。");
	setup();
	replace_program(ROOM);
}
