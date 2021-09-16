// Room: /d/shaolin/chaifang.c

#include <room.h>

inherit ROOM;

void create()
{
	set("short", "��");
	set("long", @LONG
�����������µĲ񷿣�һ����ͨ��С�����ж�����һЩ��ݡ�
��Զ����һ����ľ�գ������ջ�ɮ��æ����������Զ��ի�ã���
������������Ժ��
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "northwest" : __DIR__"houshan1",
  "east" : __DIR__"w_court",
]));

	set("objects",([
	__DIR__"npc/heshang" : 1,
]));

	setup();
        create_door("northwest", "����", "southeast", DOOR_CLOSED);
	replace_program(ROOM);
}
