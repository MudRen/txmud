// Room: /d/shaolin/houshan1.c

#include <room.h>

inherit ROOM;

void create()
{
	set("short", "��ɽ");
	set("long", @LONG
����������ɽ�ĺ�ɽ����������һ�����������Ǿ�����
�����ֵ��������ˣ�������һƬ��ʯ�ڣ�һ��С����Լ�ɼ���
LONG
	);
	set("exits", ([
	"southeast" : __DIR__"chaifang",
	"northwest" : __DIR__"houshan2",
]));

	setup();
        create_door("southeast", "����", "northwest", DOOR_CLOSED);
	replace_program(ROOM);
}
