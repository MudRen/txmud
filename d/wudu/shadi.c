// /d/wudu/shadi.c

inherit ROOM;

void create()
{
        set("short", "ɳ��");
        set("long", @LONG

LONG
        );
        set("exits", ([ 
            "northeast" : __DIR__"road16",
            "southwest" : __DIR__"shadi01",
            "southeast" : __DIR__"shadi02",
]));
        set("no_clean_up", 0);
        set("outdoors", "wudu");
        setup();
        replace_program(ROOM);
}

