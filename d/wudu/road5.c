// /d/wudu/road5.c

inherit ROOM;

void create()
{
        set("short", "��ʯ·");
        set("long", @LONG

LONG
        );
        set("exits", ([ 
            "south"     : __DIR__"hall",
            "north"     : __DIR__"gate",
            "west"      : __DIR__"road6",
            "east"      : __DIR__"road11",
]));
        set("no_clean_up", 0);
        set("outdoors", "wudu");
        setup();
        replace_program(ROOM);
}

