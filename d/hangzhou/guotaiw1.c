// /d/hangzhou/guotaiw1.c

inherit ROOM;

void create()
{
        set("short", "��̩·");
        set("long", @LONG
�����Ǻ����������һ���֣����ݸ���֪�����ž���������
�����ϣ��������·�ϵ�����Ҳ�Ƚ��٣����⣬������ϱ���
��Զ�ھ�Ҳ�������������ϡ�
LONG
        );
        set("exits", ([ 
            "south"  : __DIR__"guardgroup",
            "east"   : __DIR__"cross1",
            "west"   : __DIR__"guotaiw2",
]));
        set("outdoors", "hangzhou");
        setup();
        replace_program(ROOM);
}

