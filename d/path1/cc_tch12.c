// Room: /d/path1/cc_tch12.c

inherit ROOM;

void create()
{
	set("short", "林荫路");
	set("long", @LONG
这是一条林荫大路，路上的往来的行人越来越少了，偶尔有
个别商人经过。风一吹来，你不觉感到绿的清凉。路的两侧是一
片片的树林，林间不时传来鸟的鸣叫。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"cc_tch11",
  "north" : __DIR__"cc_tch13",
]));
	set("outdoors", "path1");
	setup();
	replace_program(ROOM);
}
