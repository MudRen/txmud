// Room: /d/path1/lmj4.c

inherit ROOM;

void create()
{
	set("short", "土路");
	set("long", @LONG
这是一条黄土小路，路的北边是一遍瓜田，南边则是一
亩亩庄稼地。路上时有行人经过，一看便知是附近的农户。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"cc_tch5",
  "east" : __DIR__"lmj3",
]));
	set("outdoors", "path1");
	setup();
	replace_program(ROOM);
}
