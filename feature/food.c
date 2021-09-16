// food.c
// Modified by Find.

#include <dbase.h>
#include <name.h>

protected nosave int decay_lasting = 360;

protected void set_decay_lasting(int n)
{
	if( (n > 0) && (n < decay_lasting) )
		return;

	decay_lasting = n;
}

int is_food() {return 1;}

void init()
{
	if(environment() == this_player())
	{
		add_action("do_eat", "eat");
		if((decay_lasting > 0) && !query("have_begun_decay"))
		{
			set("have_begun_decay",1);
			call_out("decay",decay_lasting);
		}
	}
}

protected void decay()
{
	if(!query("food_remaining"))
		return;

        tell_object(environment(),name()+"放的时间太长，烂掉了。\n");
        destruct(this_object());
}

int do_eat(string arg)
{
	object me = this_player();

	if( !arg || !this_object()->id(arg) )
		return 0;

	if( me->is_busy() )
		return notify_fail(BUSY_MESSAGE);

	if( !query("food_remaining") )
		return notify_fail( name() + "已经没什么好吃的了。\n");

	if( (int)me->query("food") >= (int)me->max_food_capacity() )
		return notify_fail("你已经吃太饱了，再也塞不下任何东西了。\n");

	me->add("food", query("food_supply"));
	if( me->is_fighting() )
		me->start_busy(1);

	if(me->query("is_bonze") && query("hun_food"))
		me->set("eat_hun_food", time());

	// 有毒的处理。
	query("drug/effect_func");

	// 用于其它特殊的 eat 效果
	if( query("eat_func") ) return 1;

	set("value", 0);
	add("food_remaining", -1);
	if( !query("food_remaining") )
	{
		message_vision(sprintf("$N将剩下的%s吃得干干净净%s。\n",
			name(),
			me->query("food") >= me->max_food_capacity()?
			"，打了个饱嗝":"" ), me);
		if( !this_object()->finish_eat() )
			destruct(this_object());
	}
	else
		message_vision("$N拿起" + name() + "咬了几口。\n", me);

	return 1;
}

void stop_decay()
{
	if(find_call_out("decay"))
		remove_call_out("decay");
	if(query("have_begun_decay"))
		set("have_begun_decay",0);
}
