// Room: /d/shaolin/qhs2.c

#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", "��ɽ");
	set("long", @LONG
����������ɽ�ĺ�ɽ����������һ�����������Ǿ�����
�����ֵ��������ˣ�������һ�����ѵ�С��ͨ��Զ����·������
һ��ʯ��(bei)������д�⼸���ʺ�Ĵ��֡�
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"qhs1",
  "west" : __DIR__"qsl/entry",
]));

	set("item_desc",([
	"ʯ��" : HIR"\nǰ���������ˣ���\n\n"NOR,
	"bei" : HIR"\nǰ���������ˣ���\n\n"NOR,
]));
	setup();
	replace_program(ROOM);
}
