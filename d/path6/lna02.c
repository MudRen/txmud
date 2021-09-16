// Room: /d/path6/lna02.c

inherit ROOM;

void create()
{
	set("short", "高原山区回廊北口");
	set("long", @LONG
这里是西藏高原山区回廊北口，南面就是回廊出口了。放眼
望去，黄中带红的山脉尽收眼底。这里空气稀薄，寒风凛冽，你
忍不住心里泛起了犹豫。不知道是否该举步向前。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"lna00/exit",
]));
        set("outdoors", "path6");
        set("cannot_build_home", 1);
        set("altitude", 4100);
	setup();
	replace_program(ROOM);
}
