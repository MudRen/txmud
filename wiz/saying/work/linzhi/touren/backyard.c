//backyard.c ��Ժ��
inherit ROOM;
void create()
{
        set("short","��Ժ");
        set("long", @LONG
������ͷ�˸��ĺ�Ժ����������Ϊ�Ǽ���ס�ĵط��������
����Ҫ��͵Ķ��ˣ�����ǰ�������������š������ǲ��ͷ�˵�
���ң������ǲ������ĵط���
LONG
        );
        set("exits", ([
        "east":__DIR__"chacha_room",
        "west":__DIR__"chacha_room2",
        "north":__DIR__"backyard2",
        "out":__DIR__"road2",
]));
        setup();
}
