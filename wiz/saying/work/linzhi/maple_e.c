//maple_e.c 枫树林迷宫的终点
inherit ROOM;

void create()
{

        set("short","枫树林");
        set("long",@long
这是一片火红的枫树林，只听风吹叶动，沙沙不绝，似乎
还有点水的气息。
long
);
        set("exits", ([ /* sizeof() == 1 */
        "north":__DIR__"maple/exit",
        "west":__DIR__"lake_e",
]));
        setup();
        replace_program(ROOM);
}
