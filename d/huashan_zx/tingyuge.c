// Room: huashan tingyuge.c by pian
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","听雨阁");
	set("long",@LONG
这是一间排设精致的房间，窗明几净，壁上挂着几幅字画。
透过窗子可以看到南边的“飞花池”。这里是华山掌门接待重要
客人的会客室。
LONG
);
	set("exits", ([ /* sizeof() == 1 */
	"west":__DIR__"zixiagong",
]));
	set("indoors", "huashan_p");
	
	setup();
	replace_program(ROOM);
}