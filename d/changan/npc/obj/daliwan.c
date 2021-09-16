// daliwan.c

inherit ITEM;

void create()
{
        set_name("大力丸", ({"dali wan","wan"}));
        set("long", "一颗黄橙橙的大力丸。\n");
        set("unit", "颗");
        set("weight", 800);
        set("value", 800);
}

void init()
{
	add_action("do_eat","eat");
}

int do_eat(string arg)
{
	object me = this_player();

	if(environment() != me)
		return 0;

	if(!arg || !id(arg))
		return notify_fail("你要吃什么？\n");

	if( me->is_busy() )
		return notify_fail(BUSY_MESSAGE);

	tell_object(me,"你拿起一颗大力丸吃了下去，觉得很甜，大概是红薯粉做的。\n");
	me->add("food",25);
        destruct(this_object());

	return 1;
}
