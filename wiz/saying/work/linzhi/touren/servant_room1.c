//servant_room1.c ����ס����
inherit ROOM;
void create()
{
        set("short","�����޴�");
        set("long", @LONG
������ͷ�˸�����ס�޵ĵط���������һ��ͨ�̣������Ǿ�
ס�����������Ȼ�������ǹ��߲����Ǻܺã���ʰ��Ҳ����
���룬�Ͼ��������ǲ���������ġ�
LONG
        );
        set("exits", ([
        "west":__DIR__"courtyard",
]));
        setup();
}
