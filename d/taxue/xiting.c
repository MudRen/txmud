// xiting.c 西厅
// by dicky

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","西厅");
        set("long",@LONG
这里是踏雪山庄接待亲朋好友的地方，案头茶几上放着四时鲜果，精
细茶点，透者主人的细心周到。临近踏雪山庄的庆典，这里更是装点的涣
然一新。仆人和丫鬟都在忙里忙外的四处奔走。
LONG);

	set("exits",([
		"east" : __DIR__"zoulang3",
		"westdown" : __DIR__"xilang2",
		"southwest" : __DIR__"shufang",
		"north" : __DIR__"xixiangfang",
	]));

        set("objects", ([
               __DIR__"npc/dizi2" : 1,
        ]));

	setup();
	replace_program(ROOM);
}
