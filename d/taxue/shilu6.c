// shilu6.c
// by dicky

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "石路");
        set("long", @LONG
这是一条青石板铺成的小路，两边绿树成荫，不时有些仆人和丫鬟从你身
边走来走去。往北走就是一直通到后山，不过，如果你的学艺不精的话，最好
不要去那里。
LONG
        );     

        set("outdoors", "taxue");

        set("exits", ([
		"south" : __DIR__"shilu5",
		"north" : __DIR__"houmen",
            ]));

        set("objects", ([
                __DIR__"npc/dizi6" : 1,
        ]));

        setup();
	replace_program(ROOM);
}
