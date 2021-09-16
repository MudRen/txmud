// gate.c

inherit ROOM;
void create()
{
        set("short", "康安寨大门");
        set("long", @LONG
你来到了康安寨大门，有几个巡视的小喽罗奇怪地盯着你，
看得你有些发毛。寨门上旌旗飞舞，高大的寨墙上有四五个喽罗
来回巡视。往北边的大路直通寨里，东边一条小路通向林阴路。
你犹豫着要不要进寨一看。
LONG
);
        set("exits", ([
                "north" : __DIR__"nroad8",
                "east" : "/d/path3/k_s9",
        ]));

        set( "GATE_ROOM",1 );
        set( "gate_dir",(["north" : __DIR__"inner_gate"]) );
        set( "close_look",@LONG
这里是康安寨的大门，夜晚大门都是关上的。
LONG
);
        set( "gate_name","康安寨大门");

        set("outdoors","path3");

        setup();
}

