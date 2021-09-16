// Room: /d/path2/hou_t22.c

inherit ROOM;

void create()
{
	set("short", "小土路");
	set("long", @LONG
这是一条草原小路，路的两侧是一片绿色的草原，草原上长
着各种各样的野花草。一些牧羊人正赶着羊群在草原上散步，另
有一群骏马驰骋在蔚蓝天空下，
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"hou_t23",
  "south" : __DIR__"hou_t21",
]));
	set("no_clean_up", 0);
	set("outdoors", "path2");
	setup();
	replace_program(ROOM);
}
