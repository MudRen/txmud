// Room: ting.c
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short",HIC"������Ϊ��"NOR);
	set("long",@LONG
�ݵر�����һ�������ʯͤ��һֻ��¯�����������̡�ʯͤ
�����ų��е����ţ�ͤ�����°��ż���ʯ�ʡ���ɽ�������糣
������СϢƬ�̡�
LONG
);
	set("exits", ([ /* sizeof() == 3 */
	"west" : __DIR__"caodi1",
	"east":__DIR__"caodi2",
	"north":__DIR__"quqiao",
]));

	set("objects", ([
            __DIR__"master/master-lh":1 ]));

	setup();
	replace_program(ROOM);
}