// Room: /d/path2/hou_t19.c

inherit ROOM;

void create()
{
	set("short", "草原小路");
	set("long", @LONG
这是一条草原小路，路的两侧是一片绿色的草原，一些牧羊
人正赶着羊群在草原上散步，另有一群骏马驰骋在蔚蓝天空下，
天际招手相见。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "southeast" : __DIR__"hou_t18",
  "northwest" : __DIR__"hou_t20",
]));
	set("no_clean_up", 0);
	set("outdoors", "path2");
	setup();
	replace_program(ROOM);
}
