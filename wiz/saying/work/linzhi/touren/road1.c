//road1.c С·��
inherit ROOM;
void create()
{
        set("short","С·");
        set("long", @LONG
������ͷ�˸�ͨ���Ժ��С·����������һЩ������Զ����
�Ǹ߸ߵ�Χǽ����С��԰���������ر��㰵�����룺��Ҫ��
ס�����ֻ������͸������ˡ�
LONG
        );
        set("exits", ([
        "south":__DIR__"garden",
        "north":__DIR__"road2",
]));
        setup();
}
