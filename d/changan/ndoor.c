// ndoor  北门

inherit ROOM;
void create()
{
        set("short", "长安城北门");
        set("long", @LONG
这里是长安城的北门，从这个门进出的多是附近的州县的百
姓来长安买卖东西的，大门上车推、肩扛、人抬、手抱各种土特
产品从门口来来往往，两个城门官累得不亦乐乎。在城门的一旁，
帖着一个布告(bugao)。从这里向南是长安城的北安大道。
LONG
        );

	set("item_desc", ([ /* sizeof() == 2 */
                "bugao": (: call_other, CRIME_D, "query_placard" :),
]));

	set("exits", ([
		"north"	:	__DIR__"out_changan_n",
                "south"            : __DIR__"nroad4",
]) );

	// gate settings
	// 此部分为 gate room 所必需的设置.

	// 这是 gate room 标记.注意 GATE_ROOM 要大写.
	set( "GATE_ROOM",1 );

	// 这是 gate 的方向,注意方向是一个 mapping.
	set( "gate_dir",(["north" : __DIR__"out_changan_n"]) );

	// 这是门关上以后看到的房间描述.
	// 规则同房间的长描述。.
	set( "close_look",@LONG
这里是长安城的北门。现在是宵禁时间，城门已经关上了。
静悄悄的只有守城的士兵们还警惕的站在这里。
LONG
);

	// 这是 gate 的名称,开关门时此房间内玩家看到的提示要用到.
	set( "gate_name","长安城北门" );

	// end.

	set("outdoors","changan");

	set("objects",([
		__DIR__"npc/city_guard" : 2,
]));
	setup();
	replace_program(ROOM);
}