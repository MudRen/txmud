// Room: /d/chengdu/out_chengdu_n.c

inherit ROOM;

void create()
{
	set("short", "成都北门外");
	set("long", @LONG
这里已经是成都府的北门外了，南面高大的成都北门已遥遥
在望，由此一直向北就是盐亭。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"ndoor",
  "north" : "/d/path5/kch56",
]));
/*
	set( "GATE_ROOM",1 );
	set( "gate_dir",(["south" : __DIR__"ndoor"]) );
	set( "close_look",@LONG
这里是成都北门外。北面一条土路静悄悄的向远处延伸，向
南看是成都的北城门，现在天色已晚，城门已经关上了。
LONG
);
	set( "gate_name","成都北门" );
*/
	set("outdoors","chengdu");

	setup();
	replace_program(ROOM);
}
