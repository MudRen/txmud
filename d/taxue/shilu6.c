// shilu6.c
// by dicky

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "ʯ·");
        set("long", @LONG
����һ����ʯ���̳ɵ�С·�������������񣬲�ʱ��Щ���˺�Ѿ�ߴ�����
��������ȥ�������߾���һֱͨ����ɽ��������������ѧ�ղ����Ļ������
��Ҫȥ���
LONG
        );     

        set("outdoors", "taxue");

        set("exits", ([
		"south" : __DIR__"shilu5",
		"north" : __DIR__"houmen",
            ]));

        set("objects", ([
                __DIR__"npc/dizi6" : 1,
        ]));

        setup();
	replace_program(ROOM);
}
