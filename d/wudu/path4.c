// /d/wudu/path4.c

inherit ROOM;

void create()
{
        set("short", "�ݵ�");
        set("long", @LONG

LONG
        );
        set("exits", ([ 
            "north"     : __DIR__"road10",
            "southeast" : __DIR__"path6",
            "southwest" : __DIR__"park",
            "east"      : __DIR__"path5",
]));
        set("no_clean_up", 0);
        set("outdoors", "wudu");
        setup();
        replace_program(ROOM);
}

