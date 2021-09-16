// Room: /d/path3/k_h37.c

inherit ROOM;

void create()
{
	set("short", "石板路");
	set("long", @LONG
你走到这里，只见地上整整齐齐地铺着青石板，地面十分清
洁，路的两侧一看就是人工裁的树林。再向南不远，就是有名的
杭州城了。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"k_h38",
  "north" : __DIR__"k_h36",
]));
	set("no_clean_up", 0);
	set("outdoors", "path3");
	setup();
	replace_program(ROOM);
}
