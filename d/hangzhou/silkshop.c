// /d/hangzhou/silkshop.c

inherit ROOM;

void create()
{
        set("short", "�������ׯ");
        set("long", @LONG
�����Ǻ��ݳ������ĳ��ׯ������˿���������������ݳ�
�ĸ���������������Ľ����������ؿ��̸������糱ӿ���ֲ�
���ƹ�ĳ���ϲЦ�տ���
LONG
        );
        set("exits", ([ 
            "north"  : __DIR__"changanw1",
]));
        setup();
        replace_program(ROOM);
}

