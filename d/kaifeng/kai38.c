// Room: /wiz/louth/k/kai38.c

inherit ROOM;

void create()
{
	set("short", "酒楼二层");
	set("long", @LONG
楼上的确比楼上讲究，不似楼下，条桌长椅，客人杂坐。
而是隔成了一个个小间，而每个小间也都挂着名牌，什么雅和
斋，会友轩，桂花寓之类。客人们也都低言慢语，不像楼下那
般人狂呼豪饮，猜拳行令。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"kai44",
  "down" : __DIR__"kai79",
]));

	setup();
	replace_program(ROOM);
}
