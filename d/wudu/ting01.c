// /d/wudu/ting01.c

inherit ROOM;

void create()
{
        set("short", "��ͤ");
        set("long", @LONG

LONG
        );
        set("exits", ([ 
            "west"     : __DIR__"path11",
            "south"    : __DIR__"jiashan",
]));
        set("no_clean_up", 0);
        set("outdoors", "wudu");
        setup();
        replace_program(ROOM);
}

