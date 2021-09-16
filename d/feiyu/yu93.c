// Room: /wiz/louth/a/yu93.c

inherit ROOM;

void create()
{
	set("short", "绯雨阁后门");
	set("long", @LONG
这里就是绯雨阁的后门，后面是一片树林，郁郁葱葱，
一条小路直通入树林之中。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 3 */
  "southeast" : __DIR__"yu94",
  "north" : __DIR__"yu92",
  "southwest" : __DIR__"xlu1",
]));

       set("outdoors","feiyu");
	setup();
	replace_program(ROOM);
}
