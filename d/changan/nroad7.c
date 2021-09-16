// /d/changan/nroad7  麒祥街

inherit ROOM;
void create()
{
        set("short", "麒祥街");
        set("long", @LONG
这里是长安城的花市，不少应时的鲜花从这里供往各地。但
是不少青楼也开在这一带，空气散发着阵阵的香气，却说不清究
竟是花香还是脂粉的香味。不远处的楼里传来阵阵姑娘们卖笑的
声音。东面和西面是长安的北大街，南面长安城最大的妓院。
LONG
        );

	set("exits", ([
                "west"            : __DIR__"nroad8",
                "south"           : __DIR__"jiyuan",
                "east"            : __DIR__"nroad6",
]) );

	set("outdoors","changan");

	set("objects",([
	__DIR__"npc/gongzi" : 1,
	__DIR__"npc/genban" : 1,
]));
        setup();
	replace_program(ROOM);
}
