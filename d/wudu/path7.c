// /d/wudu/path7.c

inherit ROOM;

void create()
{
        set("short", "�ݵ�");
        set("long", @LONG

LONG
        );
        set("exits", ([ 
            "northwest" : __DIR__"park",
            "southwest" : __DIR__"ting02",
]));
        set("no_clean_up", 0);
        set("outdoors", "wudu");
        setup();
        replace_program(ROOM);
}

