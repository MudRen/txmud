// /d/wudu/corr1.c

inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG

LONG
        );
        set("exits", ([ 
            "south"  : __DIR__"corr2",
            "north"  : __DIR__"hall",
            "east"   : __DIR__"lobby",
]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

