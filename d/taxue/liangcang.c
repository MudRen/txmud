// liangcang.c 粮仓
// by dicky

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","粮仓");
        set("long",@LONG
这里就是踏雪山庄的粮仓，里面满满的装着各种各样的食物。虽然不
能和少林、武当这些京城的大帮派相比，但是自给自足还是没问题的。由
于过几天就是踏雪山庄的大典，所以新进了一批酿酒用的高粱、面粉什么
的。你可以找找看。
LONG);

	set("exits",([
		"north" : __DIR__"shilu3",
	]));

	set("objects",([
            
	]));

	setup();
	replace_program(ROOM);
}
