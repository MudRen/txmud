// /d/wudu/path12.c

inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG

LONG
        );
        set("exits", ([ 
            "north"     : __DIR__"path11",
            "east"      : __DIR__"jiashan",
            "south"     : __DIR__"road16",
]));
        set("no_clean_up", 0);
        set("outdoors", "wudu");
        setup();
        replace_program(ROOM);
}

