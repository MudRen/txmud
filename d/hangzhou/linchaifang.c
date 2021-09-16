// Room: /d/hangzhou/linchaifang.c

inherit ROOM;

void create()
{
	set("short", "柴房");
	set("long", @LONG
这是一间柴房，里面堆满了草料以及一些马鞍，马鞭之类的
器具，屋角处有一个草炕，应该是马夫住的地方。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"linyuanzi",
]));
	set("outdoors", "hangzhou");

	setup();
	replace_program(ROOM);
}
