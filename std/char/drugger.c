//	/std/char/drugger.c
// 药店的老板，收购成品毒物。
// drugger 原意为吸毒者，自己引申为接纳毒品的人。
// 不知道其它有什么简练的叫法，就用这个词了。
// by Find.

inherit F_DEALER;

void init()
{
	::init();
	add_action("do_sell","sell");
}

int do_sell(string arg)
{
	object ob,me = this_player();
	int value;

	if(!environment())
		return 0;

	if(!is_day())
	{
		command("say 卖东西请白天再来吧。");
		return 1;
	}

	if(!stringp(arg) || !ob=present(arg,me))
		return notify_fail("您要卖什么？\n");

	if(!ob->is_poison())
		return notify_fail("我们这只收购成品的毒物用作配药的原料。\n");

	if((int)ob->query("can_use") < 1)
		return notify_fail("你的"+ob->name()+"已经没有一点毒性了，一文不值。\n");

	if(!value = ob->query("value"))
		value = ob->value();
	if(!value)
		return notify_fail("你的"+ob->name()+"毒性太小了，一文不值。\n");

	value = value*price_ratio(environment())/100;
	if(value < 1)
		value = 1;

	write(sprintf("你把%s卖掉，得到%s。\n",ob->name(),chinese_value(value)));
	pay_player(me,value);
	destruct(ob);
	return 1;
}