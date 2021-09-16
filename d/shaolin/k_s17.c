// Room: /wiz/uudd/path2/k_s17.c

inherit ROOM;

void create()
{
	set("short", "石子路");
	set("long", @LONG
这是一条石子小路，路上很干净，路两旁有几户人家。路上
静悄悄的，没有什么人。远方不时传来不知是什么东西的叫声。
你不由加快了脚步。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"k_s18",
  "north" : __DIR__"k_s16",
]));

	setup();
	set("outdoors", "shaolin");
	replace_program(ROOM);
}
