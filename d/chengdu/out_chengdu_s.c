// Room: /d/chengdu/out_chengdu_s.c

inherit ROOM;

void create()
{
	set("short", "成都南门外");
	set("long", @LONG
这里已经是成都府的南门外了，北面高大的成都南门已遥遥
在望，南面一条土路弯弯曲曲的向远方延伸。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"sdoor",
  "south" : __DIR__"scd01",
]));
/*
	set( "GATE_ROOM",1 );
	set( "gate_dir",(["north" : __DIR__"sdoor"]) );
	set( "close_look",@LONG
这里是成都南门外。南面一条土路静悄悄的向远处延伸，向
北看是成都的南城门，现在天色已晚，城门已经关上了。
LONG
);
	set( "gate_name","成都南门" );
*/
	set("outdoors","chengdu");

	setup();
	replace_program(ROOM);
}
