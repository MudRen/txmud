// /d/hangzhou/restaurant.c

inherit ROOM;

void create()
{
        set("short", "苏来客栈");
        set("long", @LONG
一进大门，你就看到大堂正墙上挂着一幅牌匾，上书五个大
字“笑迎天下客”，绕过屏风是一个大厅，桌椅板凳都码放的整
整齐齐，擦的一尘不染，看来小二甚是勤快，正想间，掌柜的迎
了过来：“客官，您是打尖，还是住店？”听起来却不是本地口
音。大厅北面有个楼梯直上二楼。门口挂着一个牌子(paizi)。
LONG
        );
        set("exits", ([ 
            "south"  : __DIR__"changanw1",
            "up"  : __DIR__"rl2",
]));

	set("item_desc", ([
		"paizi" : "楼上客房，每晚一两白银。\n",
	]));

	set(SAFE_ENV,1);
        set("no_sleep_room",1);

	set("objects",([
	__DIR__"npc/waiter" : 1,
]));
        setup();
}

int valid_leave(object me, string dir)
{

	if ( !me->query_temp("rent_paid") && dir == "up" )
		return notify_fail("李绵清一下冲到楼梯前挡住你，白眼一翻：怎么着，想白住啊！\n");
	if( me->query_temp("on_rided") && (dir == "up"))  // 判断是否骑着坐骑
		return notify_fail("李绵清挡在楼梯前说道：您老的坐骑还是留在楼下吧。\n");

	if ( me->query_temp("rent_paid") && (dir == "south") )
	return notify_fail("李绵清跑到门边拦住：客官已经付了银子，怎么不住店就走了呢！
旁人还以为小店伺候不周呢！以后谁还敢来？\n");

	return 1;
}
