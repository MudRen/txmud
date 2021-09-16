// dongting.c 东厅
// by dicky

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","东厅");
        set("long",@LONG
这里是踏雪山庄的东厅，走入东大厅，只见堂首摆放了一套紫檀木的
家具，收拾得纤尘不染，家具上摆放着一些名贵的古董，看来这里的主人
是个很有修养的人士。南面就是东东厢房。
LONG);

	set("exits",([
		"west" : __DIR__"zoulang4",
		"east" : __DIR__"donglang1",
		"north" : __DIR__"zhangfang",
		"south" : __DIR__"dongxiangfang",
	]));

        set("objects", ([
//               __DIR__"npc/jobdizi1" : 1,
        ]));

	setup();
	replace_program(ROOM);
}
