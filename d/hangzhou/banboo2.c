// Room: /d/hangzhou/banboo2.c

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
	set("no_clean_up", 0);
	set("outdoor", "hangzhou");
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"banboo1",
]));

	setup();
	replace_program(ROOM);
}
