// /d/huashan/sroad2.c

inherit ROOM;

void create()
{
        set("short", "��ʯ·");
        set("long", @LONG
������һ�����������С·�����ﵽ������ʯͷ����������
�����ѣ�ǰ����Լ�ܿ�����·����������������ʯ·��������һ
��С���֣������ǲ���ȡ�
LONG
        );
        
        set("exits", ([
                "northeast" : __DIR__"sm_wood",
                "westdown" : __DIR__"buguigu",
                "south" : __DIR__"sroad1",
        ]));

        set("outdoors","huashan");

        setup();
}

