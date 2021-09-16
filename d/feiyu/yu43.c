// Room: /u/w/wangs/a/yu43.c

inherit ROOM;

void create()
{
	set("short", "走廊");
	set("long", @LONG
你走在一条长长的走廊上，廊两边种植了大片的松柏，
郁郁葱葱，很是静谧，除了阵阵鸟语与树叶的沙沙声外，听
不到什么别的声音。南面通向几间寝室。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"yu44",
  "west" : __DIR__"yu42",
  "east" : __DIR__"yu49",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
