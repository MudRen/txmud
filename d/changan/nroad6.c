// nroad6  麒祥街

inherit ROOM;

void create()
{
        set("short", "麒祥街");
        set("long", @LONG
这里是长安城的北大街，出中长安的车市，各种香车，花辇
甚至马车都是在这里交易的。人来人往，很的喧嚣，做生意的人
不停得在夸着自己的货，虽然，你不打算买，但是光是在这里转
转，也很热闹。由这里向东和向西是宽阔的北大街延伸向远方，
北面是一家当铺。
LONG
        );

	set("exits", ([
                "west"            : __DIR__"nroad7",
		"north"           : __DIR__"hockshop",
                "east"            : __DIR__"nroad5",
]) );

	set("objects",([
	NPC_DIR"xunpu" : 1,
]));

	set("outdoors","changan");
        setup();
	replace_program(ROOM);
}
