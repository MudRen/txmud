// wofang.c 山庄卧房

inherit ROOM;

void create()
{
        set("short", "卧房");
        set("long", @LONG
没想好 呵呵
LONG
);
        set("sleep_room", "1");
        set("exits", ([
                "northeast" : __DIR__"guodao1",
]) );
 
        setup();
        replace_program(ROOM);
}

