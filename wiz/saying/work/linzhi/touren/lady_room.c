//lady_room.c ����ס����
inherit ROOM;
void create()
{
        set("short","���˾���");
        set("long", @LONG
������ͷ�˷��˵ľ��ҡ���ͷ�˵ķ���һ��������Ҳֻ�м�
������ļҾߣ���Ҳֻ�Ǽ���һ���ۺ��ɴ�ʣ�����������Ҳ��
һ��ƽ�׽��˵ĳ��ߡ�
LONG
        );
        set("exits", ([
        "west":__DIR__"backyard2",
]));
        set("objects",([
        __DIR__"npc/lady":1,
]));
        setup();
}
