// Room: guangw1.c by pian
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","�ݵ�");
	set("long",@LONG
������ϼ����������������������̺죬СϪ��ˮ��������
����Զ���������죬������ɽ������һ���õط���������һƬ��
԰�������ǻ���ϼ�����ŵ�·�ˡ�
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