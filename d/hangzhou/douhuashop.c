// /d/hangzhou/douhuashop.c

inherit ROOM;

void create()
{
        set("short", "����ׯ");
        set("long", @LONG
����һ�䲻̫��ĵ��̣���������ϸɾ����ɹ˿Ͳ��Ǻܶ�
�����Թ����嵭��ζ�ĺ����˻��ǲ�̫ϲ���Ĵ�������ζ������
̨������ƹ�Ҳ�Ե��޾���ɡ�����С�����ڵ������к�������
Ҫ��ɶ�ӣ�
LONG
        );
        set("exits", ([ 
            "north"  : __DIR__"changane1",
]));
        setup();
        replace_program(ROOM);
}

