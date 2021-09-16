// Room: /d/path5/kch27.c

inherit ROOM;

void create()
{
	set("short", "栈道");
	set("long", @LONG
这是一条人工修建的栈道，不知何年何月何人所建。你走到
这里，只见北面一道悬崖坚立，万分险峭。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "eastdown" : __DIR__"kch26",
  "eastup" : __DIR__"kch28",
]));
        set("outdoors", "path5");
        set("cannot_build_home", 1);
        set("NORIDE", "依前面的地形，你徒步还能过去，它们是没戏了。");
	setup();
	replace_program(ROOM);
}
