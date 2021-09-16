// Room: /d/path2/ch_k15.c

inherit ROOM;

void create()
{
	set("short", "高原大道");
	set("long", @LONG
你走在平坦的黄土大道上，两边是一望无际的黄土高原。一
些农户在上面种满了高粱，风一吹过，像海浪波一样此起彼伏。
由此再向北就是西峡口了。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"ch_k11",
  "south" : __DIR__"ch_k16",
]));
	set("no_clean_up", 0);
	set("outdoors", "path2");
	setup();
	replace_program(ROOM);
}
