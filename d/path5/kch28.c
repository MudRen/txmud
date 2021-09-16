// Room: /d/path5/kch28.c

inherit ROOM;

void create()
{
	set("short", "崖壁");
	set("long", @LONG
你走到这里，只见一道峻险的崖壁坚立在山路的右边，下面
是万丈深渊。你向崖壁看去，忽然感到一阵眩晕，似乎崖壁内有
什么东西在动。一块纤细的大石横空搭向东边的峭壁，没有把握
不要乱走哦。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"kch29",
  "westdown" : __DIR__"kch27",
]));
        set("outdoors", "path5");
        set("cannot_build_home", 1);
        set("NORIDE", "依前面的地形，你徒步还能过去，它们是没戏了。");
	setup();
	replace_program(ROOM);
}
