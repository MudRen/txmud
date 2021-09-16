// yazhong.c
// by dicky

#include <ansi.h>
inherit ROOM;
#include <room.h>
string look_shi();

void create ()
{
  set ("short", "半山腰");
  set ("long",@LONG
山腰上视野开阔，周围景色看的清清楚楚。山峰不知还有多高，隐
在云中不见端倪，下面云雾绕绕，也不知有多高了。前方有块柱石(shi)，
上面写着一些字，看来你如果没有特殊的事情，最好还是返回。
LONG);

	set("outdoors", "taxue");

	set("exits", ([ /* sizeof() == 3 */
	"down": "/d/houjizhen/shanya",
	]));

	set("item_desc", ([
		"shi" :  (: look_shi :),
	]));

	setup();
}

void init()
{
	add_action("do_climb", "climb");
}

string look_shi()
{
	return
	HIY"\n"
	"   ※※※※※※※※※※※※※※※   \n"
	"   ※※※                  ※※※   \n"
	"   ※※※     踏雪圣地     ※※※   \n"
	"   ※※※     有去无回     ※※※   \n"
	"   ※※※                  ※※※   \n"
        "   ※※※※※※※※※※※※※※※   \n"NOR;
}

int do_climb(string arg)
{
	object me=this_player();
	
	if( !arg || (arg!="shanya" && arg!="shan") )
		return notify_fail("你要爬什么？\n");
	if( me->is_busy())
		return notify_fail("你现在很忙，爬什么呀！\n");
	
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

	if( random((int)me->query_kar()) <= 5){
		call_out("faila", 3, me);
		return 1;
	}

	call_out("success", 3, me);
	return 1;
}
int success(object me)
{
	message_vision(HIB"$N越爬越高，渐渐隐入了云中。。。\n"NOR, me);
	me->move(__DIR__"yashang");
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
