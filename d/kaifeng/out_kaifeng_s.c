// Room: /u/w/wangs/b/kai116.c

inherit ROOM;

void create()
{
	set("short", "开封南门外");
	set("long", @LONG
这里就是开封城的南门外了，进进出出非常热闹，有的人面
带喜色，有的愁容满面，看来在开封这座商业舞台上站稳脚跟并
不是很容易的事情啊，有很多人一夜之间暴富，也有人倾刻之间
便倾家荡产。南面一条黄土路通向远方。
LONG
	);

	set("exits", ([
  "north" : __DIR__"sdoor",
  "south" : "/d/path3/k_s1",
]));
/*
        set( "GATE_ROOM",1 );
	set( "gate_dir",(["north" : __DIR__"sdoor"]) );
        set( "close_look",@LONG
这里就是开封城的南门外了，北面高大的南门遥遥在望，现
在天色已晚，城门已经关上了。四周静悄悄的，南面一条黄土路
通向远方。
LONG
);
        set( "gate_name","开封南门" );
*/
	set("outdoors","kaifeng");
	setup();
	replace_program(ROOM);
}
