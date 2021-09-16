// shadai.c

inherit ITEM;

string master;

void create()
{
	set_name("沙袋", ({ "sha dai" }) );

	set_weight(100);

	if( clonep() )
		set_default_object(__FILE__);
	else
	{
		set("unit", "个");
		set("no_get",1);
		set("long", "这是一个大沙袋晃晃悠悠的吊在两根
粗壮的竹子中间。华山弟子大部分都
是从打(da)沙袋开始练习拳脚的。\n");
	}
	setup();
}

void init()
{
	add_action("do_hit","da");
}

int do_hit(string arg)
{
	object me = this_player();
	int damage,skill;

	if(!arg || !id(arg))
		return notify_fail("你要举什么？\n");

	if(master)
		return notify_fail(master+"正在打这个沙袋，你等一下吧。\n");

	damage = (int)me->query("age")/2;

	if(me->query("kee") < damage)
		return notify_fail("你现在体力不支，还是先休息一下再说吧。\n");

	master = me->name();

	skill = me->query_skill("unarmed",1);
	message_vision("$N单膀一较力，朝着$n狠狠的打了过去。\n",me,this_object());

	me->start_busy(4);
	call_out("do_finish",2,me,damage,skill);
	return 1;
}

private void do_finish(object me,int damage,int skill)
{
	int str,improve;

	master = 0;

	if(!me || (environment(me) != environment()))
		return;

	if(skill > 50)
		tell_object(me,"沙袋飞起了老高，慢慢的停了下来。\n");
	else
	{
		if((str = me->query("str")) > 30)
			str = 30;
	
		if(skill <= 10)
			skill += 15;
		else if(skill <= 20)
			skill += 10;
		else
			skill += 5;
	
		if(random(skill) < 5)
		{
			if(!random(3))
			{
				message_vision("沙袋悠回来撞了$N一个大马爬。\n",me);
				me->receive_damage("kee",damage/2);
				return;
			}
			else
			{
				tell_object(me,"沙袋左右晃了一下，没什么反应。\n");
				me->stop_busy();
				me->receive_damage("kee",damage/2);
				return;
			}
		}

		improve = str/2 + random(str/2);
		tell_object(me,"沙袋前后悠了几下，慢慢的停了下来。\n");
		me->receive_damage("kee",damage,"tire");

		me->improve_skill("unarmed",improve);
	}

	if(me->query("combat_exp") < 30000)
		me->add("combat_exp",random(20));
	me->stop_busy();
}
