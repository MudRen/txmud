// Room: /d/path1/cc_tch6.c

inherit ROOM;

void create()
{
	set("short", "黄土路");
	set("long", @LONG
这是一条黄土大路，来往的车马激起阵阵尘土。你走在道上，
不时地擦抹着脸上汗珠。路的两侧是一片片稻田。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"cc_tch5",
  "north" : __DIR__"cc_tch7",
]));
	set("outdoors", "path1");
	setup();
	replace_program(ROOM);
}
