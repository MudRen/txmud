// Room: /d/chengdu/out_chengdu_w.c

inherit ROOM;

void create()
{
	set("short", "成都西门外");
	set("long", @LONG
这里已经是成都府的西门外了，东面高大的成都西门已遥遥
在望，西面一条土路弯弯曲曲的向远方延伸。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"wdoor",
  "west" : "/d/chengdu_w/ccg01",
]));
/*
	set( "GATE_ROOM",1 );
	set( "gate_dir",(["east" : __DIR__"wdoor"]) );
	set( "close_look",@LONG
这里是成都西门外。西面一条土路静悄悄的向远处延伸，向
东看是成都的西城门，现在天色已晚，城门已经关上了。
LONG
);
	set( "gate_name","成都西门" );
*/
	set("outdoors","chengdu");

	setup();
	replace_program(ROOM);
}
