// Room: /d/hangzhou/southdoor.c

inherit ROOM;

void create()
{
	set("short", "杭州府南门");
	set("long", @LONG
这里就是杭州城的南门。官府的卫兵正在忙着检查来往的行
人。在对面城墙上贴着一个布告(bugao)。北面不远就是杭州城
的国泰街。
LONG
	);

	set("item_desc", ([ /* sizeof() == 2 */
                "bugao": (: call_other, CRIME_D, "query_placard" :),
]));

	set("outdoors", "hangzhou");

	set("exits", ([ /* sizeof() == 1 */
		"south"	: __DIR__"out_hangzhou_s",
		"north" : __DIR__"bigroad",
]));
/*
	set( "GATE_ROOM",1 );
	set( "gate_dir",(["south" : __DIR__"out_hangzhou_s"]) );

	set( "close_look",@LONG
这里是杭州城的南门。城门已经关上了。只有守城官兵们还
站在这里四处寻看。
LONG
);
	set( "gate_name","杭州城南门" );
*/
	set("objects",([
		__DIR__"npc/city_guard" : 2,

]));

	setup();
	replace_program(ROOM);
}
