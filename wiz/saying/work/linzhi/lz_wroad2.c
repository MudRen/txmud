//lz_wroad2.c 林芝村西街
inherit ROOM;
void create()
{
        set("short","偏僻胡同");
        set("long", @LONG
这里这里是林芝村西街的一条偏僻小胡同。虽然是地处头人
大宅的前面，但是正所谓：灯下暗，这里却是整个林芝比较污秽
阴暗的地方。许多小地痞流氓都在这里聚集，然后乱七八糟的跑
到各个地方做坏事。
LONG
        );
        set("exits", ([
        "north":__DIR__"lz_wroad1",
]));
        set("objects",([
        __DIR__"npc/spalpeen":1,
]));
        setup();
}
