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
	set("exits", ([ /* sizeof() == 1 */
  "out" : __DIR__"neishi",
  "east" : __DIR__"midao2",
]));
	setup();
}
int valid_leave(object me, string dir)
{
        if (dir =="east" && me->query("gender") == "����" && me->query("class") != "rain") 
        {
                write (HIR"ͻȻһ���ҽ���������������\n"NOR);
                write ("���������û�а취��ȥ��\n");
                return 0;
        }
return ::valid_leave(me, dir);
}
