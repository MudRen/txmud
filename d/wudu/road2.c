// /d/wudu/road2.c

inherit ROOM;

void create()
{
        set("short", "�ּ�С·");
        set("long", @LONG

LONG
        );
        set("exits", ([ 
            "northeast" : __DIR__"tree2",
            "southwest" : __DIR__"road3",
]));
        set("no_clean_up", 0);
        set("outdoors", "wudu");
        setup();
        replace_program(ROOM);
}

