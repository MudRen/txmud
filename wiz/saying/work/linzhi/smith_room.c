//smith_room.c 林芝村的铁匠铺
inherit ROOM;
void create()
{
        set("short", "铁匠铺子");
        set("long", @LONG
在门外你就听见屋里叮叮当当的声音了，走进屋里你更是被
满屋的热气冲得倒退了几步。只见一位彪形大汉正在挥舞铁锤锻
造着什么，他见你进来，只是回头看你一眼，并不主动招呼你。
LONG
);
        set("exits", ([
        "north":__DIR__"lz_eroad3",
]));
        set("objects",([
        __DIR__"npc/smith" :1,
]));
        setup();
        replace_program(ROOM);
}
