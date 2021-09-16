// Room: laosong.c

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","老松树上");
	set("long",@LONG
你挂在老松树上摇摇荡荡真的很像一只大猴子。这里的风很
大，你不禁用力握了握手里的松枝。安全起见，还是不要待的太
久了吧。
LONG
);

	set("exits", ([ /* sizeof() == 3 */
	"down":__DIR__"siguoya2.c",
]));

	set("outdoors", "huashan_zx");
	setup();
}

void init()
{
	object me = this_player();
	int n = query_time();

	if( me && ((n >= 1380) || (n <= 300)) )
	{
		if( random(100 - me->query("kar")) < 10 )
			call_out("very_lucky",2,me);
	}
	add_action("do_enter", ({"pan","climb"}));
}

int do_enter(string arg)
{
	object me = this_player();
	int n = query_time();

	if( (n > 300) && (n < 1380))
		return 0;

	if( (arg != "松树枝") && (arg != "松枝") )
		return 0;

	message_vision("$N攀着老松树枝向洞口爬了过去.\n", me);

	if(me->query_skill("dodge",1) < 150)
	{
		message_vision("\n$N脚下一个不稳，向崖底摔了下去！\n\n",me);
		me->move(__DIR__"bankong");
		me->start_busy(5);
		call_out("goto_yanwang",3,me);
		return 1;
	}

	if( me->move(__DIR__"sg_dong2") )
		tell_room(environment(me), me->name() + "从外面爬了进来。\n",({me}));
	return 1;
}

private void very_lucky(object who)
{
	if(!who || !living(who) || (environment(who) != this_object()) )
		return;

	tell_object(who,WHT"\n借着皎洁的月光，你发现下面的绝壁上好像有一个洞，
攀着粗壮的松树枝也许能爬到哪里。\n\n"NOR);
}

private void goto_yanwang(object me)
{
	if(!objectp(me))
		return;

	tell_room(__FILE__,"只听得悬崖下面隐约传来一声惨叫。。。\n");

	me->stop_busy();
	me->move(__DIR__"yadi");
	me->receive_damage("kee",200,"trip");
	me->die();
}
