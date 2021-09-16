// ca_fenduo.c

inherit ROOM;
void create()
{
        set("short", "后院");
        set("long", @LONG
这里是土地庙的后院，四下荒芜，野草丛生，后墙也已经破
损不堪，经常有一些乞丐翻墙进来在此抱头而睡。南边是土地庙。
LONG
        );
        set("exits", ([
                "south" : "/d/changan/badroom",
        ]) );
        set("objects",([
                __DIR__"npc/ca_duozhu" : 1,
        ]));

        set("outdoors","changan");
        setup();
        replace_program(ROOM);
}

