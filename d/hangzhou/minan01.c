// /d/hangzhou/minan01.c

inherit ROOM;

void create()
{
        set("short", "民安北街");
        set("long", @LONG
你走在民安北街上，只见往来的行人川流不息。路的东侧是
一家书店。
LONG
        );
        set("exits", ([ 
            "south"  : __DIR__"minan02",
            "north"  : __DIR__"ndoor",
            "east"   : __DIR__"bookroom",
]));
        set("outdoors", "hangzhou");
        setup();
        replace_program(ROOM);
}

