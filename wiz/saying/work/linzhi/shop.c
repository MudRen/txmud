//shop.c ��֥����ӻ���
inherit ROOM;
void create()
{
        set("short", "�ӻ���");
        set("long", @LONG
����һ��СС�ĵ��̣�����ĳ����൱�ļ򵥣�������һ��
��̨����̨�߷���һ�����ӡ���̨��������ʽ������С��Ʒ��
������һ�����ӻ��ĵ��̡�
LONG
        );
        set("exits", ([
        "south" : __DIR__"lz_eroad3",
]));
        set("objects",([
        __DIR__"npc/shopper" : 1,
]));
        setup();
}
