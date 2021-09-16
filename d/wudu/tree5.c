// /d/wudu/tree4.c

inherit ROOM;

void create()
{
        set("short", "Ê÷ÁÖ");
        set("long", @LONG

LONG
        );
        set("exits", ([ 
            "northeast" : __DIR__"xiaoxi",
            "west"      : __DIR__"tree4",
]));
        set("no_clean_up", 0);
        set("outdoors", "wudu");
        setup();
        replace_program(ROOM);
}

