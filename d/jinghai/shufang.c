inherit ROOM;

void create()
{
        set("short", "ɽׯ�鷿");
        set("long", @LONG
û��� �Ǻ�
LONG
);

        set("exits", ([
                "north"  : __DIR__"qianyuan",
]) );

        setup();
        replace_program(ROOM);
}

