// /d/wudu/ting02.c

inherit ROOM;

void create()
{
        set("short", "��ͤ");
        set("long", @LONG

LONG
        );
        set("exits", ([ 
            "northeast" : __DIR__"path7",
            "south"     : __DIR__"tree6",
            "east"      : __DIR__"path8",
]));
        set("no_clean_up", 0);
        set("outdoors", "wudu");
        setup();
        replace_program(ROOM);
}

