// /d/wudu/jiashan.c

inherit ROOM;

void create()
{
        set("short", "��ɽ");
        set("long", @LONG

LONG
        );
        set("exits", ([ 
            "west"      : __DIR__"path12",
            "north"     : __DIR__"ting01",
            "southwest" : __DIR__"road16",
]));
        set("no_clean_up", 0);
        set("outdoors", "wudu");
        setup();
        replace_program(ROOM);
}

