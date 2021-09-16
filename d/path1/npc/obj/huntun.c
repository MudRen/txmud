// huntun.c

inherit ITEM;

void create()
{
        set_name("馄饨", ({"hun tun"}));
        set("long", "这是一碗热气腾腾的馄饨。\n");
        set("unit", "碗");
        set("weight", 800);
        set("value", 100);
}

void init()
{
	if(environment() && userp(environment()) && !query("begin"))
	{
		add_action("do_eat",({ "he", "eat" }));
		call_out("do_decay",240,0);
		set("begin",1);
	}
}

int do_eat(string arg)
{
	object me = this_player();

	if(environment() != me)
		return 0;

	if(!stringp(arg) || !id(arg))
		return 0;

	if(me->query("food") >= me->max_water_capacity())
		return notify_fail("你已经吃太饱了，再也塞不下任何东西了。\n");

	if(query("decayed"))
	{
		message_vision("$N拿起一碗馄饨刚要喝发现已经放馊了，$N随手把馄饨扔在了地上。\n",me);
		destruct(this_object());
		return 1;
	}
	me->add("food",80);
	me->add("water",30);

	message_vision("$N拿起一碗馄饨唏哩呼噜的喝了下去。\n",me);
	destruct(this_object());
	return 1;
}

void do_decay(int n)
{
	remove_call_out("do_decay");
	if(!n)
	{
		set("long", "这是一碗已经放的冰凉的馄饨。\n");
		call_out("do_decay",300,1);
		return;
	}

	else
	{
		set("long", "这是一碗已经放馊了的馄饨。\n");
		set("decayed",1);
		return;
	}
}
