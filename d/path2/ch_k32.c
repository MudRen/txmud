// Room: /d/path2/ch_k32.c

inherit ROOM;

void create()
{
	set("short", "黄土岗");
	set("long", @LONG
你走在一条黄土大道上，路的两旁是光秃秃的山丘，略平的
层地上稀稀拉拉地种着一些庄稼。远远望去，一排排的窑洞前面
一些孩子正在嬉耍。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"ch_k33",
  "northdown" : __DIR__"ch_k31",
]));

	set("objects",([
	RIDE_DIR"w_horse" : 1,
]));

	set("outdoors", "path2");
	setup();
	replace_program(ROOM);
}
