// /d/wudu/corr2.c

inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG

LONG
        );
        set("exits", ([ 
            "south"  : __DIR__"mainhall",
            "north"  : __DIR__"corr1",
            "west"   : __DIR__"bookrm",
]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

