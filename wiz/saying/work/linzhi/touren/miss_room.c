//miss_room.c С�����
inherit ROOM;
void create()
{
        set("short","С�����");
        set("long", @LONG
������ͷ��Ů���ľ��ҡ���Ȼ��ʰ�ĸɸɾ��������ǿ��Կ�
���������Ѿ��þ�û��ס���ˡ�����������ķ��䣬���е����
��������˵�����ȥ�ˡ�
LONG
        );
        set("exits", ([
        "south":__DIR__"backyard2",
]));
        setup();
}
