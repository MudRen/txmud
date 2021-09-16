// she_cha.c

inherit ITEM;

void create()
{
	set_name("蛇叉", ({ "she cha","cha"}) );
        set_weight(50);
        if( clonep() )
                set_default_object(__FILE__);
        else
	{
		set("unit", "枝");
		set("long", "这是一枝木质的蛇叉，头上绑着一个小木杈，
可以用来叉(cha)毒蛇的毒腺使其无法放毒。\n");
		set("value",500);
	}
}

void init()
{
	if(this_player()
	&& (environment() == this_player()))
		add_action("do_cha","cha");
}

int do_cha(string arg)
{
	object me = this_player(),ob;
	int status;

	if(environment() != me)
		return 0;

	if(!stringp(arg) || arg == "")
		return notify_fail("你要用蛇叉叉什么？\n");

	if(!ob = present(arg,environment(me)))
		return notify_fail("你要用蛇叉叉什么？\n");

	if( !function_exists("accept_shecha",ob) )
		return notify_fail("那不是一条毒蛇。\n");

	me->start_busy(1);
	if(!status = ob->accept_shecha(this_object()))
		return notify_fail(sprintf("你拿起蛇叉朝着%s叉了过去，但是没有叉中。\n",ob->name()));
	if(status < 0)
		return notify_fail(sprintf("%s已经备叉住了。\n",ob->name()));

	message_vision(sprintf("\n$N举起蛇叉飞身朝着%s叉了过去，蛇叉一下子卡住了毒腺。\n\n",
		ob->name()),me);
	this_object()->move(environment(me));
	return 1;
}

int valid_get(object who)
{
	delete_temp("snake");
	return 1;
}
