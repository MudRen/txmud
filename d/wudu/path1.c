// /d/wudu/path1.c

inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG

LONG
        );
        set("exits", ([ 
            "north"     : __DIR__"road4",
            "northwest" : __DIR__"path",
            "south"     : __DIR__"path2",
]));
        set("no_clean_up", 0);
        set("outdoors", "wudu");
        setup();
        replace_program(ROOM);
}

