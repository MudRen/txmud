// /d/wudu/path13.c

inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG

LONG
        );
        set("exits", ([ 
            "southwest" : __DIR__"suishi02",
            "west"      : __DIR__"tree6",
            "north"     : __DIR__"path8",
]));
        set("no_clean_up", 0);
        set("outdoors", "wudu");
        setup();
        replace_program(ROOM);
}

