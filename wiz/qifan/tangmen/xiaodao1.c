// Room: /d/tangmen/xiaodao1.c

#include <room.h>

inherit ROOM;

void create()
{
	set("short", "����С��");
	set("long", @LONG
����һ��Ƨ���Ĵ���С����С�������ǿ�֦��Ҷ������ȥ��
���������ܾ����ĵģ�ż����������������
LONG
	);
/*
	set("exits", ([
  "north" : __DIR__"yz_door",
        "southwest" : __DIR__"yaopu1",
]));
*/
	set("exits", ([
	"southeast" : __DIR__"gd3",
	"northwest" : __DIR__"xiaodao2",
]));

	set("outdoors", "tangmen");
	setup();
	create_door("southeast", "ľ��", "northwest", DOOR_CLOSED);
}
