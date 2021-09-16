// shilu2.c
// by dicky

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "石路");
        set("long", @LONG
这是一条青石板铺成的小路，两边绿树成荫，不时有些仆人和丫鬟从你身
边走来走去。往北就是西廊了，西面传出劈柴的声音，南面却显得非常静悄悄
的。
LONG
        );
        
 
	set("outdoors","taxue");

        set("exits", ([
		"north" : __DIR__"xilang1",
		"west" : __DIR__"caifang",
		"south" : __DIR__"shilu3",
        ]));          

        setup();
	replace_program(ROOM);
}
