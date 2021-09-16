// Room: xiaolu1.c by pian
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","西山小路");
	set("long",@LONG
这是一条青石傅就的小路，从西山桃林通向莲花峰，你的东
边就是紫霞宫青色的围墙。西北方有水声传来。北边是一片茂密
的桃树林。
LONG
);
	set("exits", ([ /* sizeof() == 2 */
	"southeast" : __DIR__"taolin",
	"northwest":__DIR__"xiaolu2",
]));



	set("outdoors", "huashan_p");
	setup();
	replace_program(ROOM);
}