// Room: /d/xiaoyao/thshulin3.c

inherit ROOM;

void create()
{
        set("short", "桃花迷阵");
        set("long", @LONG
这是一片桃花的海洋。四周一望无际，全是盛开的桃花。微风拂过，
落英缤纷。周围静悄悄的。远处偶尔传来一声鸟叫。  
LONG );
        set("objects", ([ ]));
        set("outdoors", "xiaoyao");
        set("exits", ([ /* sizeof() == 4 */
                "south" : __DIR__"thshulin3",
                "north" : __DIR__"thshulin3",
                "east"  : __DIR__"thshulin2",
                "west"  : __DIR__"th02",
        ]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
