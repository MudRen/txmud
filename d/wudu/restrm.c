// /d/wudu/restrm.c

inherit ROOM;

void create()
{
        set("short", "��Ϣ��");
        set("sleep_room", "1");
        set("long", @LONG

LONG
        );
        set("exits", ([ 
            "west"      : __DIR__"road13",
]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

