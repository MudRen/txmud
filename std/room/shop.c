// shop.c
// Modified by Find.
// ��ͨ�̵꣬�չ���Ʒ��

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
		log_file("shop",sprintf("%s �� %s ����ʦ��Ʒ %s ��û��. %s\n",
			geteuid(me),to_chinese(domain_file(base_name(this_object()))),
			base_name(ob),ctime(time())));
		destruct(ob);
		return notify_fail(ob->name()+"����ʦ��Ʒ��û���ˣ����������������������ͣ�\n");
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
		return notify_fail("��Ҫ��ʲô�������ۣ�\n");

	if( ob->query("money_id") )
		return notify_fail("���ǡ�Ǯ������û������\n");

	if(ob->is_food())
		return notify_fail("ʳƷ�����Լ��԰ɡ�\n");
	if(ob->is_corpse())
		return notify_fail("����˭��ʬ�׿���ߣ������⻹Ҫ�������ء�\n");
	if(ob->is_weapon())
		return notify_fail("����С��ɲ����գ���ȥ���������ʰɡ�\n");
	if(ob->is_character())
		return notify_fail("С���ط������ҷ����˿ڡ�\n");
	if(ob->query("no_drop"))
		return notify_fail("�����������겻�ա�\n");
	if(ob->is_poison())
		return notify_fail("����С��ɲ����գ�\n");
	if(ob->query("no_sell"))
		return notify_fail("�����������겻�ա�\n");

#ifdef WIZARD_FLAG
	if(!check_sell_object(this_player(),ob))
		return 0;
#endif

        value = ob->query("value");
        if( !value )
		value = ob->value(); /* combined ob's value. */
	if( !value )
		return notify_fail(sprintf("%sһ�Ĳ�ֵ��\n", ob->query("name")));

	if(value < 10)
		return notify_fail(ob->query("name")+"��ֵ̫�ͣ��ⲻ�ա�\n");
        else
	{
		value = value*price_ratio(this_object())/100;
		if(ob->query("stealing_object"))
			printf("%s����������ֵ%s��\n����͵���Ķ���С��Ҫ�����գ�ֻ����%s��\n",
				ob->query("name"),
				chinese_value(value),
				chinese_value(value/2));
		else if(ob->query("begging_object"))
			printf("%s����������ֵ%s��\n�����ֵ㶫�������ף��Ͱ�%s�հɡ�\n",
				ob->query("name"),
				chinese_value(value),
				chinese_value(value*2/3));
		else printf("%s����������ֵ%s��\n����(sell)�����õ�%s��\n",
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
		return notify_fail("��Ҫ����ʲô��Ʒ��\n");

	if( ob->query("money_id") )
		return notify_fail("��Ҫ����Ǯ����\n");
	if(ob->is_food())
		return notify_fail("ʳƷ�����Լ��԰ɡ�\n");
	if(ob->is_corpse())
		return notify_fail("����˭��ʬ�׿���ߣ������⻹Ҫ�������ء�\n");
	if(ob->is_weapon())
		return notify_fail("����С��ɲ����գ���ȥ���������ʰɡ�\n");
	if(ob->is_character())
		return notify_fail("С���ط������ҷ����˿ڡ�\n");
	if(ob->query("no_drop"))
		return notify_fail("����������������\n");
	if(ob->query("no_sell"))
		return notify_fail("�����������ܵ䵱��\n");
	if(ob->is_poison())
		return notify_fail("����С��ɲ����գ�\n");

#ifdef WIZARD_FLAG
	if(!check_sell_object(this_player(),ob))
		return 0;
#endif

	value = ob->query("value");
	if( !value )
		value = ob->value(); /* combined ob's value. */
	if( !value )
		return notify_fail("����������ֵǮ��\n");

	if(value < 10)
		return notify_fail(ob->query("name")+"��ֵ̫�ͣ��ⲻ�ա�\n");

	value = value*price_ratio(this_object())/100;
	if(ob->query("stealing_object"))
	{
		message_vision("$N������͵����" + ob->query("name") + "������\n", this_player());
		pay_player(this_player(), value/2, ob->query_credit_point_flag()?1:0);
	}

	else if(ob->query("begging_object"))
	{
		message_vision("$N��������������" + ob->query("name") + "������\n", this_player());
		pay_player(this_player(), value*2/3, ob->query_credit_point_flag()?1:0);
	}

	else
	{
		message_vision("$N�����ϵ�" + ob->query("name") + "������\n",this_player());
		pay_player(this_player(), value*8/10, ob->query_credit_point_flag()?1:0);
	}
        destruct(ob);
        return 1;
}
