// Room: /d/shaolin/e_square.c

inherit ROOM;

void create()
{
	set("short", "东广场");
	set("long", @LONG
这里是少林寺的东广场，广场很大，四下一些巨大的香炉，
不少来来往往的善男信女虔诚的敬着香。不远处的长明灯放着光
芒，几个僧人正续着香油。从这里向西是中院广场，东面是紧那
罗殿，北方和南方是过道。
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"rroad2",
  "north" : __DIR__"rroad3",
  "east" : __DIR__"jinnaluo",
  "west" : __DIR__"m_square",
]));
        set("objects",([
        __DIR__"npc/husi_seng" : 1,
]));
	set("outdoors", "shaolin");

	setup();
	replace_program(ROOM);
}
