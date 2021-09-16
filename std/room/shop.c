// shop.c
// Modified by Find.
// 普通商店，收购物品。

inherit ROOM;

#ifdef WIZARD_FLAG
private int check_sell_object(object me,object ob)
{
	string name;

	if(!objectp(me) || !objectp(ob))
		return 0;
	if(ob->query_wiz_flag() && !wizardp(me))
	{
		name = ob->name();
		log_file("shop",sprintf("%s 在 %s 卖巫师物品 %s 被没收. %s\n",
			geteuid(me),to_chinese(domain_file(base_name(this_object()))),
			base_name(ob),ctime(time())));
		destruct(ob);
		return notify_fail(ob->name()+"是巫师物品被没收了，请立刻向天神发信做出解释！\n");
	}
	else
		return 1;
}
#endif

void init()
{
        add_action("do_value", ({"value","gu"}));
        add_action("do_sell", "sell");
}

int do_value(string arg)
{
	object ob;
	int value;

	if( !arg || !(ob = present(arg, this_player())) )
		return notify_fail("你要给什么东西估价？\n");

	if( ob->query("money_id") )
		return notify_fail("这是「钱」，你没见过吗？\n");

	if(ob->is_food())
		return notify_fail("食品留着自己吃吧。\n");
	if(ob->is_corpse())
		return notify_fail("这是谁的尸首快搬走，我们这还要做生意呢。\n");
	if(ob->is_weapon())
		return notify_fail("兵器小店可不敢收，你去铁匠铺问问吧。\n");
	if(ob->is_character())
		return notify_fail("小店奉公守法，不敢贩卖人口。\n");
	if(ob->query("no_drop"))
		return notify_fail("这样东西本店不收。\n");
	if(ob->is_poison())
		return notify_fail("毒物小店可不敢收！\n");
	if(ob->query("no_sell"))
		return notify_fail("这样东西本店不收。\n");

#ifdef WIZARD_FLAG
	if(!check_sell_object(this_player(),ob))
		return 0;
#endif

        value = ob->query("value");
        if( !value )
		value = ob->value(); /* combined ob's value. */
	if( !value )
		return notify_fail(sprintf("%s一文不值。\n", ob->query("name")));

	if(value < 10)
		return notify_fail(ob->query("name")+"价值太低，这不收。\n");
        else
	{
		value = value*price_ratio(this_object())/100;
		if(ob->query("stealing_object"))
			printf("%s在我们这能值%s。\n不过偷来的东西小店要担风险，只能卖%s。\n",
				ob->query("name"),
				chinese_value(value),
				chinese_value(value/2));
		else if(ob->query("begging_object"))
			printf("%s在我们这能值%s。\n看你讨点东西不容易，就按%s收吧。\n",
				ob->query("name"),
				chinese_value(value),
				chinese_value(value*2/3));
		else printf("%s在我们这能值%s。\n卖断(sell)可以拿到%s。\n",
			ob->query("name"), chinese_value(value),
			chinese_value(value*8/10));
	}
        return 1;
}

int do_sell(string arg)
{
        object ob;
        int value;

	if( !arg || !(ob = present(arg, this_player())) )
		return notify_fail("你要卖断什么物品？\n");

	if( ob->query("money_id") )
		return notify_fail("你要卖「钱」？\n");
	if(ob->is_food())
		return notify_fail("食品留着自己吃吧。\n");
	if(ob->is_corpse())
		return notify_fail("这是谁的尸首快搬走，我们这还要做生意呢。\n");
	if(ob->is_weapon())
		return notify_fail("兵器小店可不敢收，你去铁匠铺问问吧。\n");
	if(ob->is_character())
		return notify_fail("小店奉公守法，不敢贩卖人口。\n");
	if(ob->query("no_drop"))
		return notify_fail("这样东西不能卖。\n");
	if(ob->query("no_sell"))
		return notify_fail("这样东西不能典当。\n");
	if(ob->is_poison())
		return notify_fail("毒物小店可不敢收！\n");

#ifdef WIZARD_FLAG
	if(!check_sell_object(this_player(),ob))
		return 0;
#endif

	value = ob->query("value");
	if( !value )
		value = ob->value(); /* combined ob's value. */
	if( !value )
		return notify_fail("这样东西不值钱。\n");

	if(value < 10)
		return notify_fail(ob->query("name")+"价值太低，这不收。\n");

	value = value*price_ratio(this_object())/100;
	if(ob->query("stealing_object"))
	{
		message_vision("$N把身上偷来的" + ob->query("name") + "卖掉。\n", this_player());
		pay_player(this_player(), value/2, ob->query_credit_point_flag()?1:0);
	}

	else if(ob->query("begging_object"))
	{
		message_vision("$N把身上乞讨来的" + ob->query("name") + "卖掉。\n", this_player());
		pay_player(this_player(), value*2/3, ob->query_credit_point_flag()?1:0);
	}

	else
	{
		message_vision("$N把身上的" + ob->query("name") + "卖掉。\n",this_player());
		pay_player(this_player(), value*8/10, ob->query_credit_point_flag()?1:0);
	}
        destruct(ob);
        return 1;
}
