#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", "�ص�");
	set("long", @LONG
����һ����С��ڵ��ܵ�����Χ�����ʯ���Ϲ���ˮ�飬��
���м���С�ڶ���
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"midao3",
  "east" : __DIR__"midao5",
  "south" : __DIR__"midao3",
  "north" : __DIR__"midao5",
]));
	setup();
}

int valid_leave(object me,string dir)
{
        me->receive_damage("kee",10);
        me->receive_damage("gin",10);
        me->receive_damage("sen",10);
        message_vision(HIR"���ܺ�Ȼ�������������̼���$N��ʱ����������\n"NOR,me);
return 1;
}
