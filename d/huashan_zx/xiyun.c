// Room: huashan xiyun.c by pian
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","憩云轩");
	set("long",@LONG
这是一间摆设精致的房间。靠墙摆着一个紫檀木的梳妆台，
上面有钗环脂粉等物，看来是女子的房间。
LONG
);
	set("exits", ([ /* sizeof() == 4 */
	//"up":__DIR__"ming3f",
	//"down":__DIR__"doorgd",
	//"west" : __DIR__"ming2fw1",
	"east":__DIR__"houdian",
]));
	set("objects", ([
            __DIR__"master/master-zq":1 ]));

    	setup();
	replace_program(ROOM);
}