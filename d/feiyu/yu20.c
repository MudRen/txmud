// Room: /u/w/wangs/a/yu20.c

inherit ROOM;

void create()
{
	set("short", "禁闭室");
	set("long", @LONG
这里是绯雨阁的禁闭室，当绯雨阁的弟子犯错的时候，
会把他们关在这里闭门思过，不过已经好久没有用过了。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "northeast" : __DIR__"yu19",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
