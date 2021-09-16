// /d/wudu/road4.c

inherit ROOM;

void create()
{
        set("short", "Ð¡¾¶");
        set("long", @LONG

LONG
        );
        set("exits", ([ 
            "northeast" : __DIR__"tree4",
            "northwest" : __DIR__"road3",
            "south"     : __DIR__"path1",
]));
        set("no_clean_up", 0);
        set("outdoors", "wudu");
        setup();
        replace_program(ROOM);
}

