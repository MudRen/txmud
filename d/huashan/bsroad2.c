// /d/huashan/bsroad2.c

//#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", "ɽ·");
        set("long", @LONG
������һƬ���ƶ��͵�ɽ·��Ҳ��������Ĺ�ϵ������ǿ��
����ǰ���·�������·���ʪ������֮���ƶ��ͣ�����·���
����׹��ɽ�ȵ�Σ�գ����ǿ�Щ��·Ҫ���������������Ƕ��͵�
ɽ·�����������¡�
LONG
        );
        
        set("exits", ([
                "southdown" : __DIR__"bsroad1",
                "northup" : __DIR__"bxuanya",
        ]));

        set("outdoors","huashan");

        setup();
}

