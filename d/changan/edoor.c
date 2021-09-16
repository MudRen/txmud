// edoor  东门

inherit ROOM;

void create()
{
	set("short", "长安城东门");
        set("long", @LONG
这里是长安城的东门，是专门运送贡往皇宫的皇粮的粮道，
每天都有载着粮食、瓜果蔬菜、各种牲畜的大车从这里进入京城。
两个城门官忙着检查进出的车辆和行人。在城门的一旁，帖着一
个布告(bugao)。从这里向西是长安城的东安大道。
LONG
        );

	set("item_desc", ([ /* sizeof() == 2 */
                "bugao": (: call_other, CRIME_D, "query_placard" :),
]));

	set("exits", ([
		"east"	:	__DIR__"out_changan_e",
                "west"            : __DIR__"eroad4",
]) );
/*
	// gate settings
	// 此部分为 gate room 所必需的设置.

	// 这是 gate room 标记.注意 GATE_ROOM 要大写.
	set( "GATE_ROOM",1 );

	// 这是 gate 的方向,注意方向是一个 mapping.
	set( "gate_dir",(["east" : __DIR__"out_changan_e"]) );

	// 这是门关上以后看到的房间描述.
	// 规则同房间的长描述。.
	set( "close_look",@LONG
这里是长安城的东门。现在是宵禁时间，城门已经关上了。
静悄悄的只有守城的士兵们还警惕的站在这里。
LONG
);

	// 这是 gate 的名称,开关门时此房间内玩家看到的提示要用到.
	set( "gate_name","长安城东门" );

	// end.
*/
	set("outdoors","changan");

	set("objects",([
		__DIR__"npc/city_guard" : 2,
]));
	setup();
	replace_program(ROOM);
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
                return notify_fail("守城卫兵懒洋洋地说道：嘿嘿，如果想出城，坐骑就暂时留在这里吧。\n");

	if( me->is_busy())
		return notify_fail("你现在很忙，等下再去贿赂吧！\n");

        if(ob = present("silver_money", me) ){              
		message_vision("$N拿出一两白银递给守城卫兵，点头哈腰说道：“这点银子是孝敬您的，拿去喝点茶吧。\n\n", me);
		message_vision("城头的守城卫兵看看了你，招了招手，说道：“过去吧。”，便打开城门让$N过去！\n\n", me); 
               ob->add_amount(-1);
               me->move(__DIR__ "out_changan_e");
		return 1;
               }
	if(ob = present("gold_money", me)){                  
               message_vision("$N掏了半天，发现身上白银所剩无几了，只得拿出一锭黄金递给守城卫兵，\n点头哈腰说道：“这点金子是孝敬您的，拿去喝点茶吧。。\n\n", me); 
               ob->add_amount(-1);
               me->move(__DIR__ "out_changan_e");
		return 1;
               }

	return notify_fail("你掏了掏腰包，却发现身上带的钱不够了。\n");   
}