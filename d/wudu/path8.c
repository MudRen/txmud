// /d/wudu/path8.c

inherit ROOM;

void create()
{
        set("short", "�ݵ�");
        set("long", @LONG

LONG
        );
        set("exits", ([ 
            "south"     : __DIR__"path13",
            "west"      : __DIR__"ting02",
            "northeast" : __DIR__"zhaoze",
]));
        set("no_clean_up", 0);
        set("outdoors", "wudu");
        setup();
        replace_program(ROOM);
}

