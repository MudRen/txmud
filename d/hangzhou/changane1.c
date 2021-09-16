// Room: /d/hangzhou/changane1.c

inherit ROOM;

void create()
{
	set("short", "长安东街");
	set("long", @LONG
你正走在城北的长安街上，这里向北不远就是杭州府的北城
门了，因此你可以看到不少的往来客商匆匆而过，街两旁没什么
特别繁华的地方，多是一些老字号。
LONG
	);
	set("outdoors", "hangzhou");
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"cross",
  "south" : __DIR__"douhuashop",
  "east" : __DIR__"changane2",
  "north" : __DIR__"baozishop",
]));

	setup();
	replace_program(ROOM);
}
