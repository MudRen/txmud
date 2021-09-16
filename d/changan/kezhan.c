// Room: /u/xiaozhen/kezhan.c

inherit ROOM;

void create()
{
	set("short", "高升客栈");
	set("long", @LONG
这里是长安城最大一家客栈，生意非常兴隆。在这里有南来
北往的人在这里打尖住店，其中有赶考的举子，做生意的商贾……
一进门，你就看到小二不停的忙碌着招呼着客人，正面一个高大
的柜台，两边摆着两盆常青树。柜台后是成坛成坛的洒缸，门前
挂着两个大灯笼。正中摆放着一些桌椅，早已擦的干干净净。墙
上挂着一个牌子(paizi)。
LONG
	);

	set(SAFE_ENV,1);
        set("no_sleep_room",1);

	set("item_desc", ([
		"paizi" : "楼上客房，每晚二两白银。\n",
	]));

	set("objects", ([
		__DIR__"npc/waiter_1" : 1,
	]));

	set("exits", ([
		"east" : __DIR__"sroad9",
		"up" : __DIR__"kezhan2",
	]));

	setup();
}

int valid_leave(object me, string dir)
{

	if ( !me->query_temp("rent_paid") && dir == "up" )
		return notify_fail("店小二一下挡在楼梯前，白眼一翻：怎么着，想白住啊！\n");
	if( me->query_temp("on_rided") && dir == "up")  // 判断是否骑着坐骑
		return notify_fail("店小二挡在楼梯前说道：您老的坐骑还是留在楼下吧。\n");

	if ( me->query_temp("rent_paid") && dir == "east" )
		me->delete_temp("rent_paid");

	return ::valid_leave(me, dir);
}
