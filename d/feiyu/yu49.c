// Room: /u/w/wangs/a/yu49.c

inherit ROOM;

void create()
{
	set("short", "走廊");
	set("long", @LONG
你走在一条长长的走廊上，廊两边种植了大片的松柏，
郁郁葱葱，很是静谧，除了阵阵鸟语与树叶的沙沙声外，听
不到什么别的声音。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"yu73",
  "west" : __DIR__"yu43",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
