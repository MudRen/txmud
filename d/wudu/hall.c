// /d/wudu/hall.c

inherit ROOM;

void create()
{
        set("short", "��������");
	set("valid_startroom", 1);
        set("long", @LONG

LONG
        );
        set("exits", ([ 
            "south"  : __DIR__"corr1",
            "north"  : __DIR__"road5",
            "east"   : __DIR__"gongrm",
            "west"   : __DIR__"whall",
]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

