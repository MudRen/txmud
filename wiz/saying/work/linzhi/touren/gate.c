//gate.c 林芝镇头人府大门
inherit ROOM;
void create()
{
        set("short","头人府大门");
        set("long", @LONG
这里就是林芝村头人府的大门。查查头人是林芝村有名的勇
士，十几年前圣兽肆虐的时候，就是他带领村里的一帮青年奋勇
抵抗，才保住了村民的性命财产，大家感激他的所做所为，公推
他做了村子的头人。门两旁有两个哨塔，哨塔下还有卫兵巡逻。
LONG
        );
        set("exits", ([
        "east":__DIR__"tower_e",
        "west":__DIR__"tower_w",
        "north":__DIR__"courtyard",
        "south":"/wiz/saying/work/linzhi/lz_wroad1",
]));
        set("objects",([
        __DIR__"npc/soldier":2,
]));
        setup();
}
