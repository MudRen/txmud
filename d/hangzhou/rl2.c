// /d/hangzhou/rl2.c

inherit ROOM;

void create()
{
        set("short", "������ջ��¥");
        set("long", @LONG
����¥�ݣ�ӭ����һ�������Ĺ�����һ�������ˣ����Կ���
һ���������һ����һ�ſ������Ŀͷ���
LONG
        );
        set("exits", ([ 
            "down"  : __DIR__"restaurant",
            "up"  : __DIR__"rl3",
]));
        setup();
        replace_program(ROOM);
}

