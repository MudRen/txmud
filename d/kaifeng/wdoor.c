// Room: /open/k/wdoor.c

inherit ROOM;

void create()
{
	set("short", "开封西门");
	set("long", @LONG
开封是一座通渠大城，人口众多，商业繁华，自古以来便是
兵家必争之地。坚实的城楼有五丈多高，数十名士兵整齐地站在
城门边，警惕地审视着来往匆匆的行人。城门内侧的城墙上贴着
的一张告示(gaoshi)吸引了很多人驻足围观。
LONG
	);

	set("exits",([
	"west" : __DIR__"out_kaifeng_w",
	"east" : __DIR__"kai2",
]));

        set("objects",([
        __DIR__"npc/guanbing" : 2,
]));
/*
        set( "GATE_ROOM",1 );
        set( "gate_dir",(["west" : __DIR__"out_kaifeng_w"]) );
        set( "close_look",@LONG
开封是一座通渠大城，人口众多，商业繁华，自古以来便是
兵家必争之地。这里便是开封的西门了，现在天色已晚，城门已
经关上了。
LONG
);
        set( "gate_name","开封西门" );
*/
	set("outdoors","kaifeng");
	setup();
}
