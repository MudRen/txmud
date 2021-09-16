// Room: guangw1.c by pian
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","草地");
	set("long",@LONG
沿着紫霞宫大门向西；这里是姹紫嫣红，小溪流水，虫鸣蛙
唱。远处飞瀑悬天，白云绕山。真是一个好地方。西边是一片桃
园，东边是回紫霞宫大门的路了。
LONG
);
	set("exits", ([ /* sizeof() == 2 */
	"east" : __DIR__"gongmen",
	"west":__DIR__"taolin",
]));
	set("outdoors", "huashan_p");
	setup();
	replace_program(ROOM);
}