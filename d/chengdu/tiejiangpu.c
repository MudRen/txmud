// Room: /wiz/louth/c/tiejiangpu.c

inherit ROOM;

void create()
{
	set("short", "铁匠铺");
	set("long", @LONG
这是成都的一间普通的铁匠铺，一进去就能看见对面墙壁上
挂着许多的铁器，离墙不远的地方有一张打铁用的桌子，上面放
着几把刚出炉的兵器。门边的一块木牌(pai)好像写着点什么，这
里向东就是武王道。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"wwdao5",
]));

	set("item_desc",([
	"pai" : "高价收购兵器、护甲，代客配(pei)钥匙，修理(xiuli)兵器。\n",
]));

	set("objects",([
	__DIR__"npc/smith" : 1,
]));

	setup();
	replace_program(ROOM);
}
