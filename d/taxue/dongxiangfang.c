// dongxiangfang.c 东厢房
// by dicky

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","东厢房");
        set("long",@LONG
这里也是踏雪山庄的帐房所在，花府每日钱财出入的帐目都在这里。
房里四周是一些黑色的柜子，不知放了些什么。书桌（table）上堆着小
山一样的帐簿，管家踏雪独龙正在忙碌的写着什么。 踏雪山庄的弟子可
以在这里领到不同的薪水和任务。
LONG	);

	set("exits",([
		"north" : __DIR__"dongting",
	]));
	set("item_desc", ([
		"table" : "桌上杂乱的堆着帐簿(zhang bu)。\n",
	]));
		
	set("book_count",1);

	setup();
}
void init()
{
	add_action("do_move","move");
}

int do_move(string arg)
{
	object ob;
	object me= this_player();
	object where=environment(me);
	if (arg!="zhang bu" && arg!="bu") return 0;
	if (!where->query("book_count"))
		return notify_fail("帐簿已经被人翻的乱七八糟。\n");
	ob = new(__DIR__"obj/unarmed-book");
	ob->move(where);
	message_vision("只听见“啪”的一声，一本书掉了下来。\n",me);
	set("book_count",0);
	return 1;
}