// tao.c 山桃
// 春秋两季各结果4个

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("青山桃", ({ "shan tao" }) );
	set_weight(80);

	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long","一只青色的山桃。是华山的特产。\n");
		set("unit", "只");
		set("food_remaining", 3);
		set("food_supply", 30);
	}
}

void init()
{
	if(environment() && userp(environment()) && (find_call_out("do_decay") == -1))
		call_out("do_decay",90);
	add_action("do_eat","eat");
}

int do_eat(string arg)
{
	object me = this_player();

	if(!arg || !id(arg))
		return notify_fail("你要吃什么？\n");

	message_vision("$N抓起青山桃放在嘴里，三口两口的就吃完了。\n",me);
	write("你只觉得体内气血乱撞，一股热气从丹田升起，散入四肢。\n");
	me->add("max_force",5);
	destruct(this_object());
	return 1;
}

protected void do_decay()
{
	if(environment())
		tell_object(environment(),"青山桃放的时间太长，烂掉了。\n");
	destruct(this_object());
}
