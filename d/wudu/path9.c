// /d/wudu/path9.c

inherit ROOM;

void create()
{
        set("short", "�ݵ�");
        set("long", @LONG

LONG
        );
        set("exits", ([ 
            "south"  : __DIR__"bamboo02",
            "north"  : __DIR__"zhaoze01",
]));
        set("no_clean_up", 0);
        set("outdoors", "wudu");
        setup();
        replace_program(ROOM);
}

