// gate.c

#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", "���Ź�");
        set("long", @LONG
�������������������ڡ����Źء���������ǰ������һ��
�ߴ�ĺ�ɫ��¥������������޿�������ж�ǰ������Ϊһ����
�Źؾ��޷��ٻ������ˡ�
LONG
);
        set("exits", ([
                "north" : "/d/death/gateway",
        ]) );

        set("no_magic", 1);

        setup();
	replace_program(ROOM);
}