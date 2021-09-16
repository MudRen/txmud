// zoulang2.c 走廊2

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","走廊");
        set("long",@LONG
这是通往踏雪山庄内堂的道路，北面是一个圆形的拱门，那里好象种
满了花，使得你在这里都可以闻到花香。但是又好象隐隐透着一股杀气。
你不禁打了个寒噤……
LONG);

	set("outdoors","taxue");

	set("exits",([
		"north" : __DIR__"huazhen1",
		"southwest" : __DIR__"dating",
	]));
	setup();
	replace_program(ROOM);
}
