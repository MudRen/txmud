// Room: /d/path1/cc_tch5.c

inherit ROOM;

void create()
{
	set("short", "岔路口");
	set("long", @LONG
这里是一个岔路口，是进出长安的必经之路。从这里向东，
通向鹿马集，再向南走，就要到长安城了，另有一条大路向北而
去。
LONG
	);
	set("exits", ([
  "south" : __DIR__"cc_tch4",
  "east" : __DIR__"lmj4",
  "north" : __DIR__"cc_tch6",
]));
	set("outdoors", "path1");

	set("objects",([
	__DIR__"npc/xingren" : 2,
]));

	setup();
	replace_program(ROOM);
}
