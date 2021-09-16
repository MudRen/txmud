// Room: /u/w/wangs/b/kai148.c

inherit ROOM;

void create()
{
	set("short", "开封东门外");
	set("long", @LONG
开封是一座通渠大城，人口众多，商业繁华，自古以来便是
兵家必争之地。西面是开封城坚实的东城门，数十名士兵整齐地
站在城门边，警惕地审视着来往匆匆的行人。这里不许摆摊设点，
亦不准行人随便逗留，所以显得十分整洁、严肃。东面一条大路
通向远方。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
	"west" : __DIR__"edoor",
	"east" : "/d/path3/k_h1",
]));
/*
        set( "GATE_ROOM",1 );
        set( "gate_dir",(["west" : __DIR__"edoor"]) );
        set( "close_look",@LONG
开封是一座通渠大城，人口众多，商业繁华，自古以来便是
兵家必争之地。这里便是开封的东门外面，现在天色已晚，城门
已经关上了。
LONG
);

        set( "gate_name","开封东门" );
*/
        set("outdoors","kaifeng");
	setup();
}
