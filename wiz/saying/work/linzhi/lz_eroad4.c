//lz_eroad4.c ��֥�嶫��
inherit ROOM;
void create()
{
        set("short","�嶫ɽ·");
        set("long", @LONG
�߹�ԭʼɭ�֣�ǰ����һ��С��ׯ������ȥ����ԭ�Ľ�����
�����죬Ӧ�þ�����֥�ˡ�������ס�Ĵ���ǲ����ˣ���������
ԭ�������٣�ֻ�к��ٵ���Ϊ�˱��Ѵ���ԭ�ӵ����
LONG
        );
        set("exits", ([
        "east":__DIR__"lz_eroad5",
        "west":__DIR__"lz_eroad3",
        "south":__DIR__"lz_guard",
]));
        set("objects",([
        __DIR__"npc/guardian":4,
]));
        setup();
}
