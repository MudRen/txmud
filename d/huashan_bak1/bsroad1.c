// /d/huashan/bsroad1.c

//#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", "ɽ·");
        set("long", @LONG
������һƬ���ƶ��͵�ɽ·��Ҳ��������Ĺ�ϵ������ǿ��
����ǰ���·�������·���ʪ������֮���ƶ��ͣ�����·���
����׹��ɽ�ȵ�Σ�գ����ǿ�Щ��·Ҫ���������������ǲ���ȣ�
�����Ƕ��͵�ɽ·��
LONG
        );
        
        set("exits", ([
                "southup" : __DIR__"buguigu",
                "northup" : __DIR__"bsroad2",
        ]));

        set("outdoors","huashan");

        setup();
}


