// /d/hangzhou/tangyuanshop.c

inherit ROOM;

void create()
{
        set("short", "��Բ����");
        set("long", @LONG
��ν���ӣ�������·��֧�ŵ�һ��«ϯ���ӣ��Աߵ�һ�ڴ�
������ཹ�ཱུķ����ţ�������������Ʈɢ�������ÿ�ģ����
�����������³Ե����㡣
LONG
        );
        set("exits", ([ 
            "south"  : __DIR__"changane3",
]));
        setup();
        replace_program(ROOM);
}

