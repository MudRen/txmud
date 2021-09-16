// Room: /d/changan/out_changan_s.c

inherit ROOM;

void create()
{
	set("short", "长安南门外");
	set("long", @LONG
走到这里就出了京城。北面是长安城的南门，几个官军在盘
查着过往的行人。往南看去是一条笔直的黄土大道。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
	"north" : __DIR__"sdoor",
        "south" : "/d/path2/ch_k1",
]));

// gate settings
// 此部分为 gate room 所必需的设置.

	// 这是 gate room 标记.注意 GATE_ROOM 要大写.
	set( "GATE_ROOM",1 );

	// 这是 gate 的方向,注意方向是一个 mapping.
	set( "gate_dir",(["north" : __DIR__"sdoor"]) );

	// 这是门关上以后看到的房间描述.
	// 规则同房间的长描述。.
	set( "close_look",@LONG
这里是长安城外。南面是一条黄土大路静悄悄的向远处延伸，
向北看是长安城的南门，现在天色已晚，城门已经关上了。
LONG
);

	// 这是 gate 的名称,开关门时此房间内玩家看到的提示要用到.
	set( "gate_name","长安城南门" );

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
	&& (dir == "north") )
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

void init()
{
        add_action("do_huilu", "huilu");
}

int do_huilu(string arg)
{
	object me,ob;
	me = this_player();
	if( !arg || (arg!="guard" && arg!="guanbing") )
		return notify_fail("你要贿赂谁？\n");

	if( me->query_temp("on_rided"))  // 判断是否骑着坐骑
                return notify_fail("守城卫兵懒洋洋地说道：嘿嘿，如果想进城，坐骑就暂时留在这里吧。\n");

	if( me->is_busy())
		return notify_fail("你现在很忙，等下再去贿赂吧！\n");

        if(ob = present("silver_money", me) ){              
		message_vision("$N拿出一两白银递给守城卫兵，点头哈腰说道：“这点银子是孝敬您的，拿去喝点茶吧。\n\n", me);
		message_vision("城头的守城卫兵看看了你，招了招手，说道：“过去吧。”，便打开城门让$N过去！\n\n", me); 
               ob->add_amount(-1);
               me->move(__DIR__ "sdoor");
		return 1;
               }
	if(ob = present("gold_money", me)){                  
               message_vision("$N掏了半天，发现身上白银所剩无几了，只得拿出一锭黄金递给守城卫兵，\n点头哈腰说道：“这点金子是孝敬您的，拿去喝点茶吧。。\n\n", me); 
               ob->add_amount(-1);
               me->move(__DIR__ "sdoor");
		return 1;
               }

	return notify_fail("你掏了掏腰包，却发现身上带的钱不够了。\n");   
}