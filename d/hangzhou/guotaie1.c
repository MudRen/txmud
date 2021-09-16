// Room: /d/hangzhou/guotaie1.c

inherit ROOM;

void create()
{
	set("short", "国泰路");
	set("long", @LONG
这里是杭州最宽阔的一条街，杭州府的知府衙门就座落在这
条街上，因此这条路上的行人也比较少，另外，名震大江南北的
震远镖局也座落在这条街上。
LONG
	);
	set("outdoors", "hangzhou");
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"fishshop",
  "west" : __DIR__"cross1",
  "east" : __DIR__"guotaie2",
]));

	setup();
	replace_program(ROOM);
}
