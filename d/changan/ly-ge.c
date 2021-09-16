// Room: /d/changan/ly-ge.c

inherit ROOM;

void create()
{
	set("short", "凌烟阁");
	set("long", @LONG
这是一幢华丽的楼阁，四处雕梁画栋，盈门一块先皇御赐的
匾额上书“凌烟阁”三个龙飞凤舞的大字。据说本朝先皇好武，
广结武林豪杰，当年征战四方开疆拓土多得武林朋友之助，本朝
很多开国元勋也出身武林，因此定都长安之后特建此阁定期排名
天下江湖豪杰前三名刻像供奉于此阁以示敬重与激励。
LONG
	);
        set("NONPC",1);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"ehroad1",
  "up"	: __DIR__"ly-ge2",
]));

	setup();
	replace_program(ROOM);
}
