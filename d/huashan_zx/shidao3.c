// Room: shidao3.c
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short",HIC"��ǰʯ��"NOR);
	set("long",@LONG
����һ���ӹ���ͨ����ϼ���������ʯ�̾͵�����ʯ�׿�
Լ�������У���������ʯ�����������й��ӵ�ʯ�񡣶�����һ
�ر�ˮ��������һƬ���ԡ�
LONG
);
	set("exits", ([ /* sizeof() == 2 */
	"south":__DIR__"shidao2",
	"north":__DIR__"zixiagong",
	"east":__DIR__"feihua1",
	"west":__DIR__"huacong1"
]));



	set("outdoors", "huashan_p");
	setup();
	replace_program(ROOM);
}