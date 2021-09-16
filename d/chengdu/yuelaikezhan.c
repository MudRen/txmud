// Room: /d/chengdu/yuelaikezhan.c

inherit ROOM;

void create()
{
	set("short", "悦来客栈");
	set("long", @LONG
这里就是成都的悦来客栈。过往的客商都在这里投宿，加之
店小二的热情服务，让每个来这里的人都有一种回到了家的感觉。
门口的牌子上写着：“住宿一律一两白银”，从客栈的北面出来
就能到万明路。
LONG
);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"wmlu5",
  "up" : __DIR__"kezhan2",
]));

	set("no_fight",1);

	set("objects",([
	__DIR__"npc/waiter" : 1,
]));

	setup();
}

int valid_leave(object me, string dir)
{
	if ( !me->query_temp("rent_paid") && dir == "up" )
		return notify_fail("店小二一下挡在楼梯前说道：住店交钱，概不赊欠！\n");

	if( me->query_temp("on_rided") && dir == "up")
		return notify_fail("店小二挡在楼梯前说道：您老的坐骑还是留在楼下吧。\n");

	if( dir == "north" )
		me->delete_temp("rent_paid");

	return ::valid_leave(me, dir);
}
