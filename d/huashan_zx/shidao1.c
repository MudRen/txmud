// Room: shidao1.c
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short",HIC"��ǰʯ��"NOR);
	set("long",@LONG
����һ���ӹ���ͨ����ϼ���������ʯ�̾͵�����ʯ�׿�
Լ�������У���������ʯ�����������й��ӵ�ʯ��
LONG
);
	set("exits", ([ /* sizeof() == 2 */
	"southeast" : __DIR__"guodaoe",
	"southwest":__DIR__"guodaow",
	"north":__DIR__"shidao2",
]));



	set("outdoors", "huashan_p");
	setup();
	replace_program(ROOM);
}