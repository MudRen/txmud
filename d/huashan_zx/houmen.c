// Room: houmen.c

#include <room.h>

inherit ROOM;

void create()
{
	set("short","��ϼ������");
	set("long",@LONG
���������ϼ����ǰ����Ҫ�򵥵Ķ࣬������������ͭ����
�Կ�������š��������ȥ�������������壬��ȻҲ������ɽ��
��Ҫ����Щ�����ˡ�
LONG
);
        set("exits", ([ /* sizeof() == 2 */
                "north" : __DIR__"h_dao1",
                "south" : __DIR__"guodaoe10",
        ]));

        set("outdoors", "huashan_zx");

        set("objects", ([
		//__DIR__"npc/lm_guard": 2 
        ]) );

        setup();
	create_door("north", "�������", "south", DOOR_CLOSED);
}
