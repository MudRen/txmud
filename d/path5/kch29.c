// Room: /d/path5/kch29.c

inherit ROOM;

void create()
{
	set("short", "悬空石桥");
	set("long", @LONG
这是一块悬空的纤细山石，就像桥一样，正好搭在两边的峭
壁之上。经过风吹日晒雨淋，上面长满了暗绿的苔藓。看来没练
过功夫的人很难通过。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"kch28",
  "east" : __DIR__"kch30",
]));
        set("outdoors", "path5");
        set("cannot_build_home", 1);
        set("NORIDE", "依前面的地形，你徒步还能过去，它们是没戏了。");
	setup();
	replace_program(ROOM);
}
