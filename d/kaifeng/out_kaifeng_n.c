// Room: /u/w/wangs/b/kai94.c

inherit ROOM;

void create()
{
	set("short", "开封北门外");
	set("long", @LONG
雄伟的北门是开封城的主门，所以比起其它几道城门来，它
建造得特别壮观。开阔的大道从城门里直伸向远方，一队队的士
兵整齐的在门楼上走过，这里不许摆摊设点，亦不准行人随便逗
留，所以显得十分整洁、严肃。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
	"south" : __DIR__"ndoor",
	"north" : "/d/path2/ch_k42",
]));
/*
        set( "GATE_ROOM",1 );
        set( "gate_dir",(["south" : __DIR__"ndoor"]) );
        set( "close_look",@LONG
雄伟的北门是开封城的主门，所以比起其它几道城门来，它
建造得特别壮观。现在天色已晚，城门已经关上了。
LONG
);
        set( "gate_name","开封北门" );
*/
        set("outdoors","kaifeng");
	setup();
}
