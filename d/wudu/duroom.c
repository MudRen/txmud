// /d/wudu/duroom.c

inherit ROOM;

void create()
{
        set("short", "������");
        set("long", @LONG

LONG
        );
        set("exits", ([ 
            "southwest" : __DIR__"path5",
            "southeast" : __DIR__"shuitan",
]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

