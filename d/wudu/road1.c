// /d/wudu/road1.c

inherit ROOM;

void create()
{
        set("short", "�ּ�С·");
        set("long", @LONG

LONG
        );
        set("exits", ([ 
            "southeast" : __DIR__"tree2",
            "northwest" : __DIR__"road",
            "east"      : __DIR__"tree",
]));
        set("no_clean_up", 0);
        set("outdoors", "wudu");
        setup();
        replace_program(ROOM);
}

