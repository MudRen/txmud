// upstairs.c

inherit ROOM;

void create()
{
        set("short", "空中楼阁");
        set("long", @LONG
这里是不好工作室的上空。
LONG
);

        set("no_clean_up", 1);
        set("no_sleep_room", 0);
        set("exits", ([
                "down" : __DIR__"workroom",
        ]));

        set("objects",([
        ]));

        setup();
        replace_program(ROOM);
}

