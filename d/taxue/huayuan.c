// huayuan.c
// by dicky

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","花园");
        set("long",@LONG
这里是踏雪山庄里面的花园，由于踏雪山庄弟子众多，所以这里不乏
各地的奇花异草，四季常开，争奇斗妍。这里往北就是踏雪山庄的大厅。
往南望去只见云飞云散，满目尽是云海。
LONG);

	set("outdoors","taxue");

	set("exits",([
                "out" : __DIR__"menfang",
		"north" : __DIR__"dating",
		"west" : __DIR__"zaofang",
		"southwest" : __DIR__"jiashan",
	]));

	setup();
	replace_program(ROOM);
}
