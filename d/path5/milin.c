// Room: /d/path5/milin.c

inherit ROOM;

void create()
{
	set("short", "半山密林");
	set("long", @LONG
你走进密林，只见四周阴森森一遍，不知道会有什么危险发
生。这种地方，还是不要久留的好。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" :  __DIR__"milin",
  "west" :   __DIR__"kch23",
  "east" :   __DIR__"milin",
]));
        set("outdoors", "path5");
        set("cannot_build_home", 1);
        set("NORIDE", "依前面的地形，你徒步还能过去，它们是没戏了。");
	setup();
	replace_program(ROOM);
}
