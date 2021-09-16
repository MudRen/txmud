// yashang.c
// by dicky

inherit ROOM;
#include <room.h>
#include <ansi.h>
void create ()
{
	set ("short", "万山之颠");
	set ("long", @LONG
你终于来到了山顶，这里风光秀丽，当真是好去处！山峰上视野开
阔，远望四周，把侯集镇景色看的清清楚楚。远处大海如明镜般平整。
山峰上长有无数异草，飘着淡淡香气。你惊奇的看到北边好像有一座山
庄，莫非那就是传说中的……
LONG);

        set("outdoors", "taxue");
	set("exits", ([ /* sizeof() == 3 */
		"north": __DIR__"kongdi",
	]));

	setup();
//	replace_program(ROOM);
}

void init()
{
	add_action("do_tiao", "tiao");
}

int do_tiao(string arg)
{
	object me=this_player();
	
	if( !arg || (arg!="shanya" && arg!="shan") )
		return notify_fail("你要朝哪里跳？\n");

	if( me->is_busy())
		return notify_fail("你现在很忙，爬什么呀！\n");

	if(me->query("class")!="taxue" && me->query("combat_exp")< 2000000)	
		return notify_fail("你现在实战经验还不够，无法跳下去！\n");

	if(me->query("class")=="taxue" && me->query("combat_exp")< 1000000)	
		return notify_fail("你现在实战经验还不够，无法跳下去！\n");

	if(me->query("class")!="taxue" && me->query_skill("dodge") < 200)	
		return notify_fail("你现在轻功练得还不够，无法跳下去！\n");

	if(me->query("class")=="taxue" && me->query_skill("dodge") < 160)	
		return notify_fail("你现在轻功练得还不够，无法跳下去！\n");

	message_vision(HIC"$N紧了紧随身物品，紧跟着长袖飘飘，向山崖下面飞去。\n"NOR,me);

	me->start_busy(2);

	me->move(__DIR__"yazhong");
	message_vision(HIC"$N长袖飘飘，从山崖上飞了过来，双脚轻轻着地，姿势显得是那么的优美！\n"NOR,me);
	return 1;
}