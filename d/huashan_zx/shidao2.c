// Room: shidao1.c
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short",HIC"��ǰʯ��"NOR);
	set("long",@LONG
����һ���ӹ���ͨ����ϼ���������ʯ�̾͵�����ʯ�׿�
Լ�������У���������ʯ�����������й��ӵ�ʯ�񡣶�����һ
Ƭ�ݵأ���Զһ����Կ���һ��СС��ʯͤ��
LONG
);
	set("exits", ([ /* sizeof() == 2 */
	"south":__DIR__"shidao1",
	"north":__DIR__"shidao3",
	"east":__DIR__"caodi1",
]));



	set("outdoors", "huashan_p");
	setup();
	replace_program(ROOM);
}