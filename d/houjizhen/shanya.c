// shanya.c
// by dicky

#include <ansi.h>
inherit ROOM;
#include <room.h>

void create ()
{
  set ("short", "山脚下");
  set ("long", @LONG
前方是一座高峰，半山腰上有祥云绕绕，隐有红光。由于山峰比较
陡峭，所以这里看起来象一座峭壁，峭壁上多是青苔锈葛，看上去异常
的滑手。山峰上有鹤鸣阵阵，空山回音不绝。听人说，天气好的时候常
常能听到山上有人的啸声，人多以为是神仙在上面。不过，江湖人士说
传说中的踏雪山庄好像在这附近。
LONG);

	set("outdoors", "houjizhen");

	set("exits", ([ /* sizeof() == 3 */
		"eastdown" :  __DIR__"qiaobi",
	]));

	setup();
}


void init()
{
	add_action("do_climb", "climb");
}

int do_climb(string arg)
{
	object me=this_player();
	
	if( !arg || (arg!="shanya" && arg!="shan") )
		return notify_fail("你要爬什么？\n");
	if(me->is_busy())
		return notify_fail("你很忙，爬什么呀！\n");

	message_vision(HIB"$N搓了搓手，扒着石头的缝隙向山峰上爬去。。。\n"NOR, me);
	me->start_busy(3);

	if(me->query("class")=="taxue")	
	{
	call_out("success", 0, me);
	return 1;
	}

	if(me->query("combat_exp") > 2000000)	
	{
	call_out("success", 0, me);
	return 1;
	}

	if( (int)me->query("kee") < 50 || (int)me->query("sen") < 50) {
		call_out("faila", 3, me);
		return 1;
	}

	if( (int)me->query_skill("dodge",1)+(int)me->query_skill("unarmed",1) >=10 ){
		call_out("faila", 3, me);
		return 1;
	}

	call_out("success", 3, me);
	return 1;
}
int success(object me)
{
	message_vision(HIB"$N越爬越高，渐渐隐入了云中。。。\n"NOR, me);
	me->move("/d/taxue/yazhong");
	me->receive_damage("kee", 40);
	me->receive_damage("sen", 40);
	message_vision(HIY"$N慢慢的爬了上来。\n"NOR, me);
	return 1;
}
int faila(object me)
{

        tell_object(me, "你手上一个不稳，从山峰上掉了下来。。。\n");
        tell_room(environment(me), me->name()+"晃悠悠的从山峰上掉了下来。\n", ({me, me}));
	me->unconcious();
	return 1;
}

#include "heiyijob.h";