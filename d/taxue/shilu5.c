// shilu4.c
// by dicky

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "ʯ·");
        set("long", @LONG
����һ����ʯ���̳ɵ�С·�������������񣬲�ʱ��Щ���˺�Ѿ�ߴ�����
��������ȥ�������߾���һֱͨ����ɽ��������������ѧ�ղ����Ļ������
��Ҫȥ�������������䳡��̤ѩɽׯ�ĵ����Ƕ���������ѧ������
LONG
        );     

        set("outdoors", "taxue");

        set("exits", ([
		"south" : __DIR__"wuchang1",
		"north" : __DIR__"shilu6",
		"west" : __DIR__"donglang2",
            ]));

        set("objects", ([
		__DIR__"npc/puren1":2,
        ]));

        setup();
	replace_program(ROOM);
}
