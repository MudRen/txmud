//chacha_room.c 查查头人居室
inherit ROOM;
void create()
{
        set("short","头人居室");
        set("long", @LONG
这里是查查头人的居室。屋里的布置倒也简朴，只有一个兵
器架，一张大床，一张巨大的松木桌子。整个屋子也只能称得上
是整洁而已，一点都不奢华。
LONG
        );
        set("exits", ([
        "west":__DIR__"backyard",
]));
        setup();
}
