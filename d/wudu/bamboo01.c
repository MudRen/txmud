// /d/wudu/bamboo01.c

inherit ROOM;

void create()
{
        set("short", " ����");
        set("long", @LONG

LONG
        );
        set("exits", ([ 
            "northeast" : __DIR__"bamboo02",
            "southeast" : __DIR__"shanya",
]));
        set("no_clean_up", 0);
        set("outdoors", "wudu");
        setup();
        replace_program(ROOM);
}

