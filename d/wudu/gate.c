// /d/wudu/gate.c

inherit ROOM;

void create()
{
        set("short", "կ��");
        set("long", @LONG

LONG
        );
        set("exits", ([ 
            "south"  : __DIR__"road5",
            "north"  : __DIR__"path3",
]));
        set("no_clean_up", 0);
        set("outdoors", "wudu");
        setup();
        replace_program(ROOM);
}

