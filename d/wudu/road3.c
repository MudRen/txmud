// /d/wudu/road3.c

inherit ROOM;

void create()
{
        set("short", "Ð¡¾¶");
        set("long", @LONG

LONG
        );
        set("exits", ([ 
            "northeast" : __DIR__"road2",
            "southeast" : __DIR__"road4",
            "south"     : __DIR__"path",
]));
        set("no_clean_up", 0);
        set("outdoors", "wudu");
        setup();
        replace_program(ROOM);
}

