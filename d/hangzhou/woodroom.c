// /d/hangzhou/woodroom.c

inherit ROOM;

void create()
{
        set("short", "ľ������");
        set("long", @LONG
���ݵĻҳ����У�ľ�������ø��䣬�ӹ���ʲô����������
�������æֱ�����к����͹٣�����Ҫ����Ҿߣ����������ײ�
���棿
LONG
        );
        set("exits", ([ 
            "north"  : __DIR__"changane3",
]));
        setup();
        replace_program(ROOM);
}

