// Room: ting.c
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short",HIC"草亭"NOR);
	set("long",@LONG
这里是一个小小的草亭，一个黄衣少女悠闲地坐在亭中抚着
一张古琴，弹的正是《高山》，一只香炉淡出袅袅青烟。混着枫
树的清香，真让人心旷神怡。
LONG
);
	set("exits", ([ /* sizeof() == 1 */
	"out" : __DIR__"guange2",
]));

	set("outdoors","huashan");

	set("objects", ([
            __DIR__"npc/yellow-girl":1,
            __DIR__"npc/shinv":2
]));

	setup();
	replace_program(ROOM);
}
