// yu101.c

#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", "��԰");
	set("long", @LONG
�������������С��԰����ֲ��һЩ�в�����������
��ľ�������԰��Ȼ���󣬵�����ľ������������ĳ�����
����һ�����򡣶�����һ��СԺ��
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "northwest" : __DIR__"yu100",
  "east" : __DIR__"yu102",
]));
	set("outdoors","feiyu");

	setup();
}

int valid_leave(object me, string dir)
{
	if( (dir =="east") && !wizardp(me) && (me->query("class") != "rain") )
		return notify_fail(HIM"һ������֮����ס���㡣����\n\n"NOR);
	return ::valid_leave(me, dir);
}
