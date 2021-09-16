// Room: /d/path5/kch06.c

inherit ROOM;

void create()
{
	set("short", "五霸山下");
	set("long", @LONG
这里就是五霸山脚，光秃秃的什么都没有，根本就别想见个
人影儿。由此向此一条蜿蜒小路依山而上。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "southup" : __DIR__"kch07",
  "north" : __DIR__"kch05",
]));
        set("outdoors", "path5");
        set("cannot_build_home", 1);
	setup();
	replace_program(ROOM);
}
