//fire_hole.c 德木寺塔林深处。
inherit ROOM;
void create()
{
        set("short", "塔林深处");
        set("long", @LONG
这里是德木寺塔林深处。这里乱的很，地上满是鸡毛木炭碎
骨头之类的东西，空气里弥漫着一股什么东西烧焦了的滋味，旁
边还有几只死鸡。
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
        "west":__DIR__"t_right1/exit",
]));
        set("objects",([
        __DIR__"npc/crazy_lama" : 1,
]));
        setup();
}
