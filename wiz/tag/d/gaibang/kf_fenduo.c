// kf_fenduo.c

inherit ROOM;

void create()
{
        set("short", "后花园");
        set("long", @LONG
这是一片荒废了的花园，本来这里有一片小池塘，养着一些
金鱼之类，现在池塘差不多也干涸了。池塘边立着一座假山，山
上长满了青苔。现在这里已经是丐帮的分舵所在了。
LONG
);

        set("no_clean_up", 0);
        set("no_sleep_room", 0);
        set("exits", ([
                "west" : "/d/kaifeng/kai190",
        ]));

        set("objects",([
        __DIR__"npc/kf_duozhu" : 1,
        ]));

        set("outdoors", "kaifeng");

        setup();
        replace_program(ROOM);
}

