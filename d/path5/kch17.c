// Room: /d/path5/kch17.c

inherit ROOM;

void create()
{
	set("short", "碎石坡");
	set("long", @LONG
这里是碎石坡，不知是那一年山体滑坡造就的。脚踩上去，
一阵滑动，发出哗哗的声响。石缝中挣扎着长出绿绿的小草，你
见到此景，不由得联想到生命的顽强。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "southdown" : __DIR__"kch18",
  "northup" : __DIR__"kch16",
]));
        set("outdoors", "path5");
        set("cannot_build_home", 1);
        set("NORIDE", "依前面的地形，你徒步还能过去，它们是没戏了。");
	setup();
	replace_program(ROOM);
}
