// Room: huashan houdian.c by pian
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","��ϼ�����");
	set("long",@LONG
�������������������ϼ���ˡ�������ש�̵أ��������ǻ�
��������������������������鷿��
LONG
);
	set("exits", ([ /* sizeof() == 4 */
	"east":__DIR__"cuizhulin",
	"west":__DIR__"xiyun",
	"north" : __DIR__"guodaoe10",
	"south":__DIR__"zixiagong",
]));
	set("indoors", "huashan_p");
	setup();
	replace_program(ROOM);
}