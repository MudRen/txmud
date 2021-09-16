// Room: /d/path5/w18.c

inherit ROOM;

void create()
{
	set("short", "高原小路");
	set("long", @LONG
这是一条荒凉的高原小路，只见前后左右都是半人多高的杂
草，不时有风吹过，晃动的高草就像大海波浪此起彼伏。再向西
走就是一坐小镇。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "eastdown" : __DIR__"w17",
]));
        set("outdoors", "path5");
//        set("cannot_build_home", 1);
	setup();
	replace_program(ROOM);
}
