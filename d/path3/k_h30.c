// Room: /d/path3/k_h30.c

inherit ROOM;

void create()
{
	set("short", "林荫路");
	set("long", @LONG
你走到这里，只见四周林木显得格外清新，仿佛刚刚接受过
雨水的洗礼。地上的花草也长得十分娇艳，江南的风景的确与众
不同。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"k_h31",
  "north" : __DIR__"k_h29",
]));
	set("no_clean_up", 0);
	set("outdoors", "path3");
	setup();
	replace_program(ROOM);
}
