// /d/path3/k_h35.c

inherit ROOM;

void create()
{
        set("short", "������");
        set("long", @LONG
������������¡���˵�����ն����ڴˣ�����Ů���ֹ�����
�ľ������Ҷ�������������������������ĺ��񲻶��ˡ�������
һƬ���֣��ֱ�����һ�����ӡ�
LONG
);
        set("item_desc", ([
                "����" : "
                  northwest    �����ɿ�
                  south        ���ݳ� 
",
        ]));

        set("exits", ([
                "south" : "/d/path3/k_h36",
                "northwest" : "/d/path3/k_h34",
                "west" : __DIR__"hz_maze/entry",
                "east" : __DIR__"hz_maze/exit",
        ]));

        set("outdoors", "hangzhou");

        setup();
}

