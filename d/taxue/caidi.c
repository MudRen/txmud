// caidi.c
// by dicky

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short","�˵�");
        set("long", @LONG
������һ������Ĳ�԰���������Ͳˣ��ܲ������ӣ�˿��֮�ࡣ��Χ����
�ʶ����ˣ�����Ҫ�����ˡ����ڳ��ڵò������õ��չˣ��˵����Ӳݴ�������
�Ĳ˶����Ʋ��ã�����ģ��ض����ˡ�
LONG
        );

        set("outdoors", "taxue");
        
        set("exits", ([
		"south" : __DIR__"houyuan",
		"north" : __DIR__"shilu4",
        ]) );

        setup();
        replace_program(ROOM);
}

