// Room: /d/hangzhou/out_hangzhou_n.c

inherit ROOM;

void create()
{
	set("short", "杭州城北门外");
	set("long", @LONG
从这里就出了杭州城。南面是杭州城的北门几个官军在盘查
着过往的行人。城的北面是一条黄土大道。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
	"south" : __DIR__"ndoor",
	"north" : "/d/path3/k_h40",
]));
/*
	set( "GATE_ROOM",1 );
	set( "gate_dir",(["south" : __DIR__"ndoor"]) );

	set( "close_look",@LONG
这里是杭州城外。北面是一条黄土大路，向南是杭州城的北
门，城门已经关上了。
LONG
);

	set( "gate_name","杭州城北门" );
*/
	set("outdoors","hangzhou");
	setup();
	replace_program(ROOM);
}
