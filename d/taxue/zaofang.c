// zaofang.c  糟坊
// by dicky

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","糟坊");
        set("long",@LONG
刚一进来，一股浓烈的酒香扑鼻而来。踏雪山庄在这万山之颠却以酿
酒著名于世，这里就是踏雪山庄造酒的地方。糟坊分为缸窑和窖室，以为
高粱饭发酵之用。此时正值酿酒之期，所以这里特别忙碌。
LONG);

	set("exits",([
		"east"  : __DIR__"huayuan",
		"down" : __DIR__"gangyao",
		"enter"  : __DIR__"jiaoshi",
	]));
	setup();
	replace_program(ROOM);
}
