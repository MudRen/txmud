// Room: /d/path5/na11.c

inherit ROOM;

void create()
{
	set("short", "丛林小路");
	set("long", @LONG
这是一条丛林小路，路的两边长着高低不齐的灌木。你不禁
打起精神，要是一不小心被扎伤就不值了。小路傍依地势蜿蜒向
南，走起来也满吃力的。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"na10",
  "north" : __DIR__"na12",
]));
        set("outdoors", "path5");
	setup();
	replace_program(ROOM);
}
