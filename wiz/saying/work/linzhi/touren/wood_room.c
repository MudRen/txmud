//wood_room.c ͷ�˸��񷿡�
inherit ROOM;
void create()
{
        set("short","��");
        set("long", @LONG
������ͷ�˸��Ĳ񷿣���Ҫ�ǹ�������ȼ���õġ�
LONG
        );
        set("exits", ([
        "east":__DIR__"garden",
]));
        set("objects",([
        __DIR__"npc/servant_gaci":1,
]));
        setup();
}
