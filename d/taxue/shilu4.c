// shilu4.c
// by dicky

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "ʯ·");
        set("long", @LONG
����һ����ʯ���̳ɵ�С·�������������񣬲�ʱ��Щ���˺�Ѿ�ߴ�����
��������ȥ�������߾������ã������ǰ���̤ѩɽׯ��������������λ�ĵط�
��������һƬ�س���̤ѩ������Ҫ���������
LONG
        );     

        set("outdoors", "taxue");

        set("exits", ([
		"north" : __DIR__"citang",
		"south" : __DIR__"caidi",
		"west" : __DIR__"fenmu",
            ]));

        setup();
	replace_program(ROOM);
}
