// /d/wudu/tree11.c

inherit ROOM;

void create()
{
        set("short", "Ê÷ÁÖ");
        set("long", @LONG

LONG
        );
        set("exits", ([ 
            "east"      : __DIR__"shanya",
            "west"      : __DIR__"suishi01",
]));
        set("no_clean_up", 0);
        set("outdoors", "wudu");
        setup();
        replace_program(ROOM);
}

