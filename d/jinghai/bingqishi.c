inherit ROOM;

void create()
{
        set("short", "山庄兵器房");
        set("long", @LONG
没想好 呵呵
LONG
);

        set("exits", ([
                "north"  : __DIR__"houmen",             
]) );

        setup();
        replace_program(ROOM);
}

