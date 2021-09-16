// /d/wudu/jinglou.c

inherit ROOM;

void create()
{
        set("short", "Ê¥¾­¸ó");
        set("long", @LONG

LONG
        );
        set("exits", ([ 
            "west" : __DIR__"path6",
            "up"   : __DIR__"jinglou1",
]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

