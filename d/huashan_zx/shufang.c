// Room: huashan shufang.c

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","�鷿");
	set("long",@LONG
���ǻ�ɽ��������Ⱥ���鷿��ƽʱ������ʱ��������Ҳ����
�������飬�������Ǿ���������������ȥ�ġ�
LONG
);
	set("exits", ([ /* sizeof() == 4 */
	"east" : __DIR__"zixiagong",
]));

	set("objects", ([
	__DIR__"master/master-ning":1
]));

	set(SAFE_ENV,1);

	setup();
	replace_program(ROOM);
}