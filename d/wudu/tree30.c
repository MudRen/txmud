// /d/wudu/tree30.c

inherit ROOM;

void create()
{
        set("short", "Ê÷ÁÖ");
        set("long", @LONG

LONG
        );
        set("exits", ([ 
            "southeast" : __DIR__"road7",
]));
        set("no_clean_up", 0);
        set("outdoors", "wudu");
        setup();
        replace_program(ROOM);
}

