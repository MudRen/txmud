//courtyard.c ��֥��ͷ�˸���Ժ
inherit ROOM;
void create()
{
        set("short","��Ժ");
        set("long", @LONG
��������֥��ͷ�˸��Ĵ�Ժ�����ܵ�Χǽ�������ƣ�������
��Ѳ�����ϵ�ɱ�����ڵ��������㲻�������Լ��ǲ����߽��˼�
������ʱҲ�м���ū���߹������Ǽ��Ҵ�ս����������������ʲ
ô�����ģ������������������Ϣ�ĵط���
LONG
        );
        set("exits", ([
        "east":__DIR__"servant_room1",
        "west":__DIR__"servant_room2",
        "north":__DIR__"main",
        "south":__DIR__"gate",
]));
        setup();
}
