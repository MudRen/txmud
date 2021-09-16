// wroad4  西安大道

inherit ROOM;
void create()
{
        set("short", "西安大道");
        set("long", @LONG
这里是长安城的西安大道，往东直通皇城的西门，是往皇宫
禁地运送水的水道。每天有成车的泉水从这里运进皇宫，不时有
押水的官员，高喝着“回避”。这里是永泰路与西安大道交叉路
口，西边不远就是长安城的西门。
LONG
        );

	set("exits", ([
                "north"            : __DIR__"wroad3",
                "west"             : __DIR__"wdoor",
                "east"             : __DIR__"wroad9",
                "south"            : __DIR__"wroad5",
]) );

	set("outdoors","changan");

	set("objects",([
	__DIR__"npc/shusheng" : 1,
]));

        setup();
	replace_program(ROOM);
}