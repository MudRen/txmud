// Room: huashan zixiagong.c by pian
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","��ϼ��");
	set("long",@LONG
�������������������ϼ���ˡ�������ש�̵أ��������ǻ�
�������������ǻ�ɽ�ɵ������Ҳ���ǻ���ݡ�������������
��Ⱥ���鷿��
LONG
);
	set("exits", ([ /* sizeof() == 4 */
	"north":__DIR__"houdian",
	"west":__DIR__"shufang",
	"east" : __DIR__"tingyuge",
	"south":__DIR__"shidao3",
]));
	set("indoors", "huashan_p");
	setup();
	replace_program(ROOM);
}