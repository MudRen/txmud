// /d/wudu/path.c

inherit ROOM;

void create()
{
        set("short", "�ݵ�");
        set("long", @LONG

LONG
        );
        set("exits", ([ 
            "southeast" : __DIR__"path1",
            "north"     : __DIR__"road3",
]));
        set("no_clean_up", 0);
        set("outdoors", "wudu");
        setup();
        replace_program(ROOM);
}

