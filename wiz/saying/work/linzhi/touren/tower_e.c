//tower_e.c ͷ�˸�������
inherit ROOM;
void create()
{
        set("short","����");
        set("long", @LONG
������ͷ�˸���������������ȫ��ͷ�����ϵ����֣���ʵ��
��ͷ�˲�����ǰ��ͷ��һ��ϲ������������ֻ�������λ���ϴ�
���ˣ������е����ϰ����
LONG
        );
        set("exits", ([
        "west":__DIR__"gate",
        "up":__DIR__"uptower_e",
]));
        setup();
}
