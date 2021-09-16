// shilu4.c
// by dicky

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "石路");
        set("long", @LONG
这是一条青石板铺成的小路，两边绿树成荫，不时有些仆人和丫鬟从你身
边走来走去。往北走就是祠堂，那里是安放踏雪山庄历代列祖列宗灵位的地方
，西面有一片坟场，踏雪氏死后都要被安葬那里。
LONG
        );     

        set("outdoors", "taxue");

        set("exits", ([
		"north" : __DIR__"citang",
		"south" : __DIR__"caidi",
		"west" : __DIR__"fenmu",
            ]));

        setup();
	replace_program(ROOM);
}
