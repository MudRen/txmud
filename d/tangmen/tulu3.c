// Room: /d/tangmen/tulu3.c

#include <room.h>

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
������һ�����Ĺ���������ש�̾͵ĵ���ǳ����࣬����
�Ǻ�����ĵ����ˣ�����Ļ���ÿ����������һ�����˴��
�������������ԣ�������������书�����ǵ���֮���������ڴˣ�
���˸о���Ī����ѹ����
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"xiaolu1",
  "east" : __DIR__"hqdoor",
  "west" : __DIR__"tulu2",
]));

	set("outdoors", "tangmen");
	setup();
	create_door("north", "ľ��", "south", DOOR_CLOSED);
}
