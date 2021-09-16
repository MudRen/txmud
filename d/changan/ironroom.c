// /d/changan/ironroom.c 铁器作坊

inherit ROOM;

void create()
{
        set("short", "铁器作坊");
        set("long", @LONG
这里是一家长安城一家铁匠铺。往里走，一个打铁用的大铁
墩子，旁边炉火中发出“呼呼”的声音。铁墩子旁边摆满了铁锤、
火剪和一些打铁用的器皿。屋里的光线不是很明亮。门口挂着一
块铁牌(paizi)。向东出了屋，就是连德街。
LONG
        );

	set("item_desc",([
		"paizi" : "高价收购兵器、护甲，代客配(pei)钥匙，修理(xiuli)兵器。\n",
]));
	set("exits", ([
	"east"          : __DIR__"eroad6",
	]) );

	set("objects",([
		__DIR__"npc/smith" :1,
]));
        setup();
	replace_program(ROOM);
}
