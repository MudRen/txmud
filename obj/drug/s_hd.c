// s_hd.c
// 修复 50 气的上限。

// Find.

inherit ITEM;

void create()
{
	set_name("小还丹", ({ "xiao hd", "huandan" }) );
	set_weight(50);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "颗");
		set("long", "这是一颗秘制小还丹，专治跌打损伤。\n");
		set("value", 1500);
	}
}

void init()
{
	add_action("do_eat",({ "eat","fu" }));
}

int do_eat(string arg)
{
	object me = this_player();
	int max_k,eff_k,add;

	if( !arg || !id(arg) )
		return 0;

	if(environment() != me)
		return 0;

	max_k = me->query("max_kee");
	eff_k = me->query("eff_kee");

	add = ((max_k - eff_k) > 50)?50:(max_k - eff_k);

	if(!add)
	{
		write("你服下一颗小还丹，觉得没什么反应。\n");
		destruct(this_object());
		return 1;
	}

	me->add("eff_kee",add);

	write("你服下一颗小还丹，觉得身上的伤口开始慢慢的愈合了。\n");
	destruct(this_object());
	return 1;
}