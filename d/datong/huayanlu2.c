// Room: /open/dt/huayanlu2.c

inherit ROOM;

void create()
{
	set("short", "华严路");
	set("long", @LONG
这是一条宽阔的大街，路面打扫得干干净净，这条街道是大
同城里最每华的街道之一，虽然这里没有什么大的店铺，可是因
为南方来的商人大多汇集在这条街上，所以很多商贩都在华严路
上设了很多地摊。北面一个马房，南面是一间民居。
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"huayanlu1",
  "east" : __DIR__"huayanlu3",
  "south" : __DIR__"minju3",
  "north" : __DIR__"mafang",
]));

	set("outdoors","datong");

	set("objects",([
	NPC_DIR"stdnpc/stdnpc_2" : 2,
]));

	setup();
	replace_program(ROOM);
}
