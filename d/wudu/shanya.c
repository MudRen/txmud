// /d/wudu/shanya.c

inherit ROOM;

void create()
{
        set("short", "ɽ��");
        set("long", @LONG

LONG
        );
        set("exits", ([ 
            "northwest" : __DIR__"bamboo01",
            "east"      : __DIR__"tree7",
            "west"      : __DIR__"tree11",
]));
        set("no_clean_up", 0);
        set("outdoors", "wudu");
        setup();
        replace_program(ROOM);
}

