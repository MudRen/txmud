//road2.c С·��
inherit ROOM;
void create()
{
        set("short","С·");
        set("long", @LONG
������ͷ�˸�ͨ���Ժ��С·����������һЩ������Զ����
�Ǹ߸ߵ�Χǽ����С��԰���������ر��㰵�����룺��Ҫ��
ס�����ֻ������͸������ˡ�ǰ�����Ǻ�Ժ��
LONG
        );
        set("exits", ([
        "south":__DIR__"garden",
        "enter":__DIR__"backyard",
]));
        set("outdoors","linzhi");
        setup();
}
