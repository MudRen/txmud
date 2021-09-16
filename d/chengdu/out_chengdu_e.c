// Room: /d/chengdu/out_chengdu_e.c

inherit ROOM;

void create()
{
	set("short", "成都东门外");
	set("long", @LONG
这里已经是成都府的东门外了，西面高大的成都东门已遥遥
在望，东面一条土路弯弯曲曲的向远方延伸。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"edoor",
]));
/*
	set( "GATE_ROOM",1 );
	set( "gate_dir",(["west" : __DIR__"edoor"]) );
	set( "close_look",@LONG
这里是成都东门外。东面一条土路静悄悄的向远处延伸，向
西看是成都的东城门，现在天色已晚，城门已经关上了。
LONG
);
	set( "gate_name","成都东门" );
*/
	set("outdoors","chengdu");

	setup();
	replace_program(ROOM);
}
