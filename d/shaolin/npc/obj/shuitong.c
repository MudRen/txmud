// shuitong.c

inherit ITEM;

void create()
{
	set_name("水桶", ({"shui tong"}));
        set("long",
                "这是一只大木桶，奇怪的是桶底竟然是尖的。\n");
        set("unit", "只");
        set("weight", 5000);
        set("value", 10);
	set("no_put",1);
	set("no_water",1);
}

void init()
{
	if( userp(environment()) )
		add_action("do_go","go");
	else
		call_out("do_check",1);
}

int do_go(string arg)
{
	object me = this_player();

	if( !me || (environment() != me) || query("no_water"))
		return 0;

	if(me->query("kee") < 10)
	{
		write("你已经累坏了，还是歇一会儿再走吧。\n");
		return 1;
	}

	if("/cmds/std/go"->main(me,arg))
	{
		me->receive_damage("kee",6,"tire");
		me->add_temp("shaolinjob/dashui",1);
		return 1;
	}

	return 0;
}

void do_check()
{
	if(environment()->is_room() && !query("no_water"))
	{
		tell_room(environment(),"水桶一歪，桶里的水洒了一地。\n");
		set("no_water",1);
	}
}