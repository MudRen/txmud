//hotel3.c ��֥��ջ�ͷ���

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "�ͷ�");
	set("long", @LONG
����һ���С�Ŀͷ�������ʮ�ּ�ª���ǳ��ɾ�����ǽ����
һ��ľ����ǽ�Ͽ���һ�Ȳ���Ĵ�����
LONG
);
	
	set("sleep_room", 1);
	set(SAFE_ENV,1);
	set("hotel",1);

	set("exits", ([
        "west" : __DIR__"hotel2",
	]));

	setup();
	create_door("west", "����", "east", DOOR_CLOSED);
}
