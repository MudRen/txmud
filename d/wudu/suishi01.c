// /d/wudu/suishi01.c

inherit ROOM;

void create()
{
        set("short", "��ʯ��");
        set("long", @LONG

LONG
        );
        set("exits", ([ 
            "east"      : __DIR__"tree11",
            "northwest" : __DIR__"suishi02",
]));
        set("no_clean_up", 0);
        set("outdoors", "wudu");
        setup();
        replace_program(ROOM);
}

