// shilu1.c
// by dicky

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "ʯ·");
        set("long", @LONG
����һ����ʯ���̳ɵ�С·�������������񣬲�ʱ��Щ���˺�Ѿ�ߴ�����
��������ȥ�������߾��Ǻ�Ժ�ˣ��˵أ���԰�Ͳ񷿶������������һ����
�ȣ����ŵ�������������������Ӳ��ɵġ�����������������
LONG
        );     

        set("outdoors", "taxue");

        set("exits", ([
               "north" : __DIR__"houyuan",
               "south" : __DIR__"xilang1",
            ]));
        
            set("objects", ([
           __DIR__"npc/puren" : 1,
       ]));

        setup();
	replace_program(ROOM);
}
