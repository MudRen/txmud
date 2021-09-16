// /d/wudu/suishi02.c

inherit ROOM;

void create()
{
        set("short", "ÀÈ Øµÿ");
        set("long", @LONG

LONG
        );
        set("exits", ([ 
            "southeast" : __DIR__"suishi01",
            "northwest" : __DIR__"tree6",
            "northeast" : __DIR__"path13",
]));
        set("no_clean_up", 0);
        set("outdoors", "wudu");
        setup();
        replace_program(ROOM);
}

