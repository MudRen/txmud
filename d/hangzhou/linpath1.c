// Room: /d/hangzhou/linpath1.c

inherit ROOM;

void create()
{
	set("short", "小路");
	set("long", @LONG
这里是一条长廊，曲曲折折的延伸出去，东面尽头是林家的
后花园，西面则可以到达内院和贮藏室，不时有家丁和丫鬟走过
这里。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"linneiyuan",
  "east" : __DIR__"linpath2",
  "north" : __DIR__"linstoreroom",
]));
	set("outdoors", "hangzhou");

	setup();
	replace_program(ROOM);
}
