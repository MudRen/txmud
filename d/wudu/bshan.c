// /d/wudu/bshan.c

inherit ROOM;

void create()
{
        set("short", "��ɽ");
        set("long", @LONG

LONG
        );
        set("exits", ([ 
//            "north"     : __DIR__"tree7",
//            "east"      : __DIR__"tree9",
            "northeast" : __DIR__"tree10",
]));
        set("no_clean_up", 0);
        set("outdoors", "wudu");
        setup();
        replace_program(ROOM);
}

