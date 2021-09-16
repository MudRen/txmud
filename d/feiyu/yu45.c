// Room: /u/w/wangs/a/yu45.c

inherit ROOM;

void create()
{
	set("short", "走廊");
	set("long", @LONG
你走在一条长长的走廊上，廊两边种植了大片的松柏，
郁郁葱葱，很是静谧，除了阵阵鸟语与树叶的沙沙声外，听
不到什么别的声音。东、西、南三方向各有一间寝室。
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"slroom1",
  "north" : __DIR__"yu44",
  "east" : __DIR__"slroom",
]));

	setup();
}

int valid_leave(object me,string dir)
{
	if( (dir == "west") || (dir == "east") )
	{
		if( (me->query("class") != "rain") && !wizardp(me) )
			return notify_fail("屋子里传来一个声音：此地只能菲雨阁弟子进入。\n说着把你推了出来。\n");
	}
	return ::valid_leave(me,dir);
}
