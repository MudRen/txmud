// Room: huashan shufang.c

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","书房");
	set("long",@LONG
这是华山掌门岳不群的书房。平时他不在时，弟子们也到这
里来看书，但是他是决不允许你把书带出去的。
LONG
);
	set("exits", ([ /* sizeof() == 4 */
	"east" : __DIR__"zixiagong",
]));

	set("objects", ([
	__DIR__"master/master-ning":1
]));

	set(SAFE_ENV,1);

	setup();
	replace_program(ROOM);
}