// upstairs.c

inherit ROOM;

void create()
{
        set("short", "����¥��");
        set("long", @LONG
�����ǲ��ù����ҵ��Ͽա�
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

