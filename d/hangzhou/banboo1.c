// Room: /d/hangzhou/banboo1.c

inherit ROOM;

void create()
{
	set("short", "竹林");
	set("long", @LONG
你发现自己正处身于一片幽静的竹林，远离市集
的喧嚣，只有偶尔经过的翠鸟才会打破这沁人的静寂
。
LONG
	);
	set("outdoors", "hangzhou");
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"forest1",
  "north" : __DIR__"rockroad3",
]));

	set("objects",([
	NPC_DIR"stdnpc/stdnpc_3" : 4,
]));

	setup();
	replace_program(ROOM);
}
