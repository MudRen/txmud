// jiaoshi.c
// by dicky

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","窖室");
        set("long",@LONG
这里就是踏雪山庄的酿酒室，由于酿酒的工艺流程很复杂。所以这里
分工很细，人也特别多些。但是从忙碌的现场来看，还是觉得人手不够。
尤其过几天就是踏雪山庄出酒之期，所以时间特别紧。
LONG);

	set("exits",([
		"out" : __DIR__"zaofang",
	]));
        set("objects",([
                
        ]));
	setup();
	replace_program(ROOM);
}
