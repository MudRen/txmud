// Room: /d/tangmen/xiaolu1.c

#include <room.h>

inherit ROOM;

void create()
{
	set("short", "С·");
	set("long", @LONG
����һ��С��·�������Ӳݴ������ǳ������������Ӻ�����
�������������һ��Сľ�ţ�������һƬ�����ԡ�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"jingji1",
  "south" : __DIR__"tulu3",
]));

	set("outdoors", "tangmen");
	setup();
	create_door("south", "ľ��", "north", DOOR_CLOSED);
}
