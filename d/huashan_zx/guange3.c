// Room: guange3.c by pian
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","������");
	set("long",@LONG
��Ҷ���б����Ѫ��������뻳�У����ŵ������ĺ��⡣
ԶԶ�����������ߴ�����Զ���ٴ�Ĺ��������򶫱�����·��ͨ
����˼���¡��ģ���û�з���Ͳ���ȥ�ˡ�
LONG
);
	set("exits", ([ /* sizeof() == 2 */
	"west" : __DIR__"guange2",
	"southeast":"/d/huashan/xiaolu6",
	"northeast":__DIR__"guange4",
]));
	set("outdoors", "huashan_p");
	setup();
	replace_program(ROOM);
}