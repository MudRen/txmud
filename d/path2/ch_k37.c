// Room: /d/path2/ch_k37.c

inherit ROOM;

void create()
{
	set("short", "黄土大道");
	set("long", @LONG
你走在一条黄土大道上，路的两侧是一排排的防风林。轻风
吹过，发出哗哗地声响。不时有三两匹快马从你身边经过，你小
心地往旁边闪了闪。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "northeast" : __DIR__"ch_k36",
  "south" : __DIR__"ch_k38",
]));
	set("no_clean_up", 0);
	set("outdoors", "path2");
	setup();
	replace_program(ROOM);
}
