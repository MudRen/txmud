// Room: /d/chengdu/kezhan3.c

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
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"kezhan2",
]));

	set("sleep_room", 1);
	set(SAFE_ENV, 1);
	set("hotel",1);

	setup();
	create_door("south", "����", "north", DOOR_CLOSED);
}
