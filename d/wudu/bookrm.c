// /d/wudu/bookrm.c

inherit ROOM;

void create()
{
        set("short", "�鷿");
        set("long", @LONG

LONG
        );
        set("exits", ([ 
            "east"  : __DIR__"corr2",
]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

