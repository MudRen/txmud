// Room: xiaolu1.c by pian
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","��ɽС·");
	set("long",@LONG
����һ����ʯ���͵�С·������ɽ����ͨ�������壬��Ķ�
�߾�����ϼ����ɫ��Χǽ����������ˮ��������������һƬï��
�������֡�
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