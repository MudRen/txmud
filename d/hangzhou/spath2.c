// Room: /d/hangzhou/spath2.c

inherit ROOM;

void create()
{
	set("short", "黄土大道");
	set("long", @LONG
这是一条黄土大道，路上来往的行人和商旅和你擦肩而过。
过往车辆扬起的尘土掩饰不住繁华的景象，再向北是通向杭州城
的大道。路的东面是一家小店，西面是一片树林。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"stree2",
  "south" : __DIR__"scross",
  "east" : __DIR__"sstore",
  "north" : __DIR__"spath1",
]));
	set("outdoors", "hangzhou");

	setup();
	replace_program(ROOM);
}
