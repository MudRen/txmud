// Room: /open/k/kai63.c

inherit ROOM;

void create()
{
	set("short", "城南客栈");
	set("long", @LONG
客栈门前竖着一根旗杆，旗杆顶端挑着的一只大大的红灯笼
上写着“城南客栈”。这家客栈生意非常好，南来北往的客商们
大多在这里歇脚，客栈共分三进，最外面的大堂上摆了十来张桌
子，供客人们进餐。后面的两幢楼房就是客房了。墙上挂着一个
木牌子(paizi)。
LONG
	);
	set("no_sleep_room", 1);
	set(SAFE_ENV,1);
	set("item_desc", ([ /* sizeof() == 1 */
  "paizi" : "楼上客房，每晚三两白银。
",
]));
	set("objects", ([ /* sizeof() == 1 */
	__DIR__"npc/waiter" : 1,
]));
	set("exits", ([ /* sizeof() == 2 */
  "up" : __DIR__"kezhan2",
  "east" : __DIR__"kai113",
]));

	setup();
}

int valid_leave(object me, string dir)
{

	if ( !me->query_temp("rent_paid") && dir == "up" )
		return notify_fail("店小二一下挡在楼梯前，白眼一翻：怎麽着，想白住啊！\n");
	if( me->query_temp("on_rided") && dir == "up")  // 判断是否骑着坐骑
		return notify_fail("店小二挡在楼梯前说道：您老的坐骑还是留在楼下吧。\n");

	if ( me->query_temp("rent_paid") && dir == "east" )
	return notify_fail("店小二跑到门边拦住：客官已经付了银子，怎麽不住店就走了呢！
旁人还以为小店伺候不周呢！以后谁还敢来？\n");

	return ::valid_leave(me, dir);
}
