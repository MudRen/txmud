// /d/wudu/tree20.c

inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG

LONG
        );
        set("exits", ([ 
//            "south"     : __DIR__"road13",
//            "west"      : __DIR__"road11",
            "southeast" : __DIR__"tree20",
]));
        set("no_clean_up", 0);
        set("outdoors", "wudu");
        setup();
        replace_program(ROOM);
}

