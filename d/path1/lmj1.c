// Room: /d/path1/lmj1.c

inherit ROOM;

void create()
{
	set("short", "小路");
	set("long", @LONG
一条黄土小路通向前方，路的左边是一遍瓜田，右边则是一
亩亩庄稼地。路上时有行人经过，一看便知是附近的农户。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"lmj2",
  "north" : __DIR__"py10",
]));

	set("objects",([
	__DIR__"npc/nongfu" : 1,
]));

	set("outdoors", "path1");
	setup();
	replace_program(ROOM);
}
