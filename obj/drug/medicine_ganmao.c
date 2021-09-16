// medicine_ganmao.c
// Find.

inherit ITEM;

void create()
{
	set_name("感冒药", ({ "cold medicine", "medicine" }) );
	set_weight(50);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "剂");
		set("long", "这是一剂专门医治感冒发烧的药品。\n");
		set("value", 100);
	}
}

void init()
{
	add_action("do_eat",({ "eat","fu" }));
}

int do_eat(string arg)
{
	object me = this_player();

	if( !arg || !id(arg) )
		return 0;

	if(environment() != me)
		return 0;

	write("你服下一剂感冒药，");
	if(!me->query_condition("ganmao"))
	{
		write("觉得味道有一点苦。\n");
		destruct(this_object());
		return 1;
	}

	me->apply_condition("ganmao",1);
	write("觉得身体好多了。\n");
	destruct(this_object());
	return 1;
}