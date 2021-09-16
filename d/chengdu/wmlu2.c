// Room: /wiz/louth/c/wmlu2.c

inherit ROOM;

void create()
{
	set("short", "万明路");
	set("long", @LONG
这是成都北面的万明路。向南是一座小茶馆，成都以泡茶馆
闻名，那里成天都顾客盈门。东面一直走是一条僻静的小巷。
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"chaguan",
  "west" : __DIR__"wmlu3",
  "east" : __DIR__"wmlu1",
]));

	set("outdoors","chengdu");

	setup();
	replace_program(ROOM);
}
