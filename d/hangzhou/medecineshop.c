// /d/hangzhou/medecineshop.c

inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
�����Ǻ�������������ҩ�̣������ﵽ��������һ����ҩ
�����㡣��̨�ϰ���һ̨���ӣ���̨��������һλ�ɷ���ǵ���
�ˣ����Ǳ��ص���ҽ����ҽ��
LONG
        );
        set("exits", ([ 
            "north"  : __DIR__"changanw3",
]));
        setup();
        replace_program(ROOM);
}

