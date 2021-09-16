// /d/wudu/gelou.c

inherit ROOM;

void create()
{
        set("short", "ÆÆ¾É¸óÂ¥");
        set("long", @LONG

LONG
        );
        set("exits", ([ 
            "east"  : __DIR__"road9",
            "up"    : __DIR__"gelou1",
]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

