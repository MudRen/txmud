// shilu2.c
// by dicky

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "ʯ·");
        set("long", @LONG
����һ����ʯ���̳ɵ�С·�������������񣬲�ʱ��Щ���˺�Ѿ�ߴ�����
��������ȥ���������������ˣ����洫�����������������ȴ�Ե÷ǳ�������
�ġ�
LONG
        );
        
 
	set("outdoors","taxue");

        set("exits", ([
		"north" : __DIR__"xilang1",
		"west" : __DIR__"caifang",
		"south" : __DIR__"shilu3",
        ]));          

        setup();
	replace_program(ROOM);
}
