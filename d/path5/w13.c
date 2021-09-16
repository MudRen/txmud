// Room: /d/path5/w13.c

inherit ROOM;

void create()
{
	set("short", "高原小路");
	set("long", @LONG
这是一条荒凉的高原小路，你抬眼看去，只见前后左右都是
半人多高的杂草，一眼看不到边际。不时有风吹过，晃动的高草
就像大海波浪此起彼伏，却看不到一丝人迹。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "eastdown" : __DIR__"w12",
  "westup" : __DIR__"w14",
]));
        set("outdoors", "path5");
//        set("cannot_build_home", 1);
	setup();
	replace_program(ROOM);
}
