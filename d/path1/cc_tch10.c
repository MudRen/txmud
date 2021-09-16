// Room: /d/path1/cc_tch10.c

inherit ROOM;

void create()
{
	set("short", "黄土路");
	set("long", @LONG
这是一条黄土大路，路上的行人已经不多见了。你走在黄土
高原上，不时地擦抹着脸上汗珠。路的两侧是一片片的树林。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"cc_tch9",
  "north" : __DIR__"cc_tch11",
]));
	set("outdoors", "path1");
	setup();
	replace_program(ROOM);
}
