// Room: /open/k/sdoor.c

inherit ROOM;

void create()
{
	set("short", "开封南门");
	set("long", @LONG
这里就是开封城的南大门了，宽阔的南大街上到处是南来北
往的商客，有的人面带喜色，有的愁容满面，看来在开封这座商
业舞台上站稳脚跟并不是很容易的事情啊，有很多人一夜之间暴
富，也有人倾刻之间便倾家荡产，人世间的悲欢离合就在这里一
幕幕的上演着。西面是立山街东边是向阳街。
LONG
	);

	set("exits", ([ /* sizeof() == 3 */
	"west" : __DIR__"kai61",
	"north" : __DIR__"kai113",
	"east" : __DIR__"kai166",
	"south" : __DIR__"out_kaifeng_s",
]));

        set("objects",([
        __DIR__"npc/guanbing" : 2,
]));
/*
        set( "GATE_ROOM",1 );
	set( "gate_dir",(["south" : __DIR__"out_kaifeng_s"]) );
        set( "close_look",@LONG
这里就是开封城的南门了，高大坚固的的城门耸立在眼前。
现在天色已晚，城门已经关上了。
LONG
);
        set( "gate_name","开封南门" );
*/
	set("outdoors","kaifeng");

	setup();
	replace_program(ROOM);
}
