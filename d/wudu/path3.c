// /d/wudu/path3.c

inherit ROOM;

void create()
{
        set("short", "�ݵ�");
        set("long", @LONG

LONG
        );
        set("exits", ([ 
            "south"     : __DIR__"gate",
            "north"     : __DIR__"path2",
]));
        set("no_clean_up", 0);
        set("outdoors", "wudu");
        setup();
        replace_program(ROOM);
}

