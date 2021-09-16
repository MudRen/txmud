// Room: /d/changan/out_changan_n.c

inherit ROOM;

void create()
{
	set("short", "长安北门外");
	set("long", @LONG
走到这里就出了京师。南面是长安城的北门几个官军在盘查
着过往的行人。往北看去是一条连结长安和奉天的黄土大道。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"ndoor",
  "north" : __DIR__"ch-ft1",
  "west" : "/d/houjizhen/shulin1",
]));

// gate settings
// 此部分为 gate room 所必需的设置.

	// 这是 gate room 标记.注意 GATE_ROOM 要大写.
	set( "GATE_ROOM",1 );

	// 这是 gate 的方向,注意方向是一个 mapping.
	set( "gate_dir",(["south" : __DIR__"ndoor"]) );

	// 这是门关上以后看到的房间描述.
	// 规则同房间的长描述。.
	set( "close_look",@LONG
这里是长安城外。北面是一条黄土大路静悄悄的向远处延伸，
向南看是长安城的北门，现在天色已晚，城门已经关上了。
LONG
);

	// 这是 gate 的名称,开关门时此房间内玩家看到的提示要用到.
	set( "gate_name","长安城北门" );

// end.
	set("outdoors","changan");
	setup();
}

int valid_leave(object ob,string dir)
{
	object *inv;

	if(!ob || !stringp(dir))
		return 1;

	if( userp(ob)
	&& !wizardp(ob)
	&& (dir == "south") )
	{
		inv = filter_array(deep_inventory(ob),
			(: $1->is_character()
			&& ( $1->query("attitude") == "killer"
			|| $1->query("attitude") == "aggressive" ) :));

		if(sizeof(inv))
			return notify_fail(sprintf("突然从边上跳出两个卫士说道：敢带%s进城害人，活的不耐烦啦！\n",
				inv[0]->query("name")));
	}

	return ::valid_leave(ob,dir);
}

