// /d/wudu/path10.c

inherit ROOM;

void create()
{
        set("short", "»¨´Ô");
        set("long", @LONG

LONG
        );
        set("exits", ([ 
            "northeast" : __DIR__"road15",
            "west"      : __DIR__"shuitan",
            "south"     : __DIR__"path11",
]));
        set("no_clean_up", 0);
        set("outdoors", "wudu");
        setup();
        replace_program(ROOM);
}

