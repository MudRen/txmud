// Room: /u/w/wangs/b/kai27.c

inherit ROOM;

void create()
{
    set("short", "长青路");
	set("long", @LONG
这条路全以卵石铺就，两边种着一排挺直的松树，曲曲折折
的伸向一片居民区中。路上行人较为稀少，因为男人们都忙着到
集市上赚钱去了，女人则在家中操持家务，只有晚上她们才能抽
出一点空来到广场上休息。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"kai29",
  "south" : __DIR__"kai25",
  "west" : __DIR__"kai28",
]));

	set("outdoors","kaifeng");
	setup();
	replace_program(ROOM);
}
