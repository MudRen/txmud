// /d/wudu/tree6.c

inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG

LONG
        );
        set("exits", ([ 
            "southeast"  : __DIR__"suishi02",
            "north"      : __DIR__"ting02",
            "east"       : __DIR__"path13",
]));
        set("no_clean_up", 0);
        set("outdoors", "wudu");
        setup();
        replace_program(ROOM);
}

