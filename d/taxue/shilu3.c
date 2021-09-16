// shilu2.c
// by dicky

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "石路");
        set("long", @LONG
这是一条青石板铺成的小路，两边绿树成荫，不时有些仆人和丫鬟从你身
边走来走去。往北就是回到西厅的路，南面就是踏雪山庄的粮仓了，而东面是
储藏室，这里是踏雪山庄的重地，所以经常有人来巡逻。
LONG
        );

	set("outdoors","taxue");

        set("exits", ([
		"north" : __DIR__"shilu2",
		"east" : __DIR__"chucangshi",
		"south" : __DIR__"liangcang",
        ]));          

        setup();
	replace_program(ROOM);
}
