// /d/wudu/road.c

inherit ROOM;

void create()
{
        set("short", "�ּ�С·");
        set("long", @LONG

LONG
        );
        set("exits", ([ 
            "southeast" : __DIR__"road1",
//  "north" : __DIR__"wumen",
]));
        set("no_clean_up", 0);
        set("outdoors", "wudu");
        setup();
        replace_program(ROOM);
}

