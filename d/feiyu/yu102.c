#include <room.h>
inherit ROOM;

void create()
{
	set("short", "СԺ");
	set("long", @LONG
����һ��СԺ��������������ľ��������������������
��Ķ����������ƺ���һ��С�ţ�����ľ����ӳ���������֡�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"yu103",
  "west" : __DIR__"yu101",
]));
        set("objects", ([
        __DIR__"npc/shibi3" : 1,
        __DIR__"npc/shibi4" : 1,
                        ]) );
       set("outdoors","feiyu");

	setup();
       create_door("north", "ľ��", "south", DOOR_CLOSED);
}
