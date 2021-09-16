// /d/hangzhou/ndoor.c  北门

inherit ROOM;
void create()
{
        set("short", "杭州城北门");
        set("long", @LONG
这里就是杭州城的北门。官府的卫兵正在忙着检查来往的行
人。在对面城墙上贴着一个布告(bugao)。南面就是杭州城的民
安街。
LONG
        );

	set("item_desc", ([ /* sizeof() == 2 */
                "bugao": (: call_other, CRIME_D, "query_placard" :),
]));

	set("exits", ([
		"north"	:	__DIR__"out_hangzhou_n",
                "south"            : __DIR__"minan01",
]) );
/*
	set( "GATE_ROOM",1 );
	set( "gate_dir",(["north" : __DIR__"out_hangzhou_n"]) );

	set( "close_look",@LONG
这里是杭州城的北门。城门已经关上了。只有守城官兵们还
站在这里四处寻看。
LONG
);
	set( "gate_name","杭州城北门" );
*/
	set("objects",([
		__DIR__"npc/city_guard" : 2,

]));
	set("outdoors","hangzhou");
	setup();
	replace_program(ROOM);
}