// Room: ting.c
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short",HIC"��ͤ"NOR);
	set("long",@LONG
������һ��СС�Ĳ�ͤ��һ��������Ů���е�����ͤ�и���
һ�Ź��٣��������ǡ���ɽ����һֻ��¯�����������̡����ŷ�
�������㣬�������Ŀ�������
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
