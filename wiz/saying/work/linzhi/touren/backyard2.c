//backyard2.c ��Ժ��
inherit ROOM;
void create()
{
        set("short","��Ժ");
        set("long", @LONG
������ͷ�˸��ĺ�Ժ����������Ϊ�Ǽ���ס�ĵط��������
����Ҫ��͵Ķ��ˣ�����ǰ�������������š�������ͷ�˷��˵�
���ң�������������̷��˵�Ѿ��ס�ĵط���
LONG
        );
        set("exits", ([
        "east":__DIR__"lady_room",
        "west":__DIR__"servant_room3",
        "north":__DIR__"miss_room",
        "south":__DIR__"backyard",
]));
        setup();
}
