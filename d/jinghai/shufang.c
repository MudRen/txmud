inherit ROOM;

void create()
{
        set("short", "山庄书房");
        set("long", @LONG
没想好 呵呵
LONG
);

        set("exits", ([
                "north"  : __DIR__"qianyuan",
]) );

        setup();
        replace_program(ROOM);
}

