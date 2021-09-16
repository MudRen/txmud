// /d/changan/wroad9  西安大道

inherit ROOM;

void create()
{
        set("short", "西安大道");
        set("long", @LONG
这里是长安城的西安大道，往东直通皇城的西门，是往皇宫
禁地运送水的水道。每天有成车的泉水从这里运进皇宫，不时有
押水的官员，高喝着“回避”。这里往西直通长安城的西门，往
东是长安的内环城路的西环路。
LONG
        );

	set("exits", ([
		"west"             : __DIR__"wroad4",
		"east"             : __DIR__"whroad2", ]) );

	set("outdoors","changan");

	set("objects",([
	__DIR__"npc/shusheng" : 1,
]));

	setup();
	replace_program(ROOM);
}
