// /d/wudu/park.c

inherit ROOM;

void create()
{
        set("short", "��԰");
        set("long", @LONG

LONG
        );
        set("exits", ([ 
            "northeast" : __DIR__"path4",
            "southeast" : __DIR__"path7",
            "southwest" : __DIR__"chanchi",
]));
        set("no_clean_up", 0);
        set("outdoors", "wudu");
        setup();
        replace_program(ROOM);
}

