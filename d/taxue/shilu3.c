// shilu2.c
// by dicky

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "ʯ·");
        set("long", @LONG
����һ����ʯ���̳ɵ�С·�������������񣬲�ʱ��Щ���˺�Ѿ�ߴ�����
��������ȥ���������ǻص�������·���������̤ѩɽׯ�������ˣ���������
�����ң�������̤ѩɽׯ���صأ����Ծ���������Ѳ�ߡ�
LONG
        );

	set("outdoors","taxue");

        set("exits", ([
		"north" : __DIR__"shilu2",
		"east" : __DIR__"chucangshi",
		"south" : __DIR__"liangcang",
        ]));          

        setup();
	replace_program(ROOM);
}
