// finance.c
// Modified by Find.

nomask int check_money(object money,object me)
{
	if(!money || !me)
		return 0;

	if(!sscanf(file_name(money),"/obj/money/%*s"))
	{
		sys_log("wiz_ob",sprintf("(%s)��ͼ��α��(%s)������Ʒ��û��.(%s)\n",
		geteuid(me),base_name(money),ctime(time())));
		destruct(money);
		tell_object(me,"�����ϵ�α����û���ˡ�\n");
		return 0;
	}

#ifdef WIZARD_FLAG
	if( money->query_wiz_flag() && !wizardp(me) )
	{
		sys_log("wiz_ob",sprintf("(%s)��ͼ����ʦ����Ǯ(%s:%d)������Ʒ��û��.(%s)\n",
		geteuid(me),money->query("id"),money->query_amount(),ctime(time())));
		destruct(money);
		tell_object(me,"�����ϴ�����ʦ�����Ǯ��û����,����������������������,�������Ը�.\n");
	}
#endif
	else
		return 1;
}

nomask varargs void pay_player(object who, mixed amount, int cp_flag)
{
        int i,flag = 0;
        object ob;
	float g_value,s_value,c_value,v;
	string *ll;

	if(!who || !amount)
		return;

#ifdef WIZARD_FLAG
	if(previous_object() && previous_object()->query_wiz_flag() && !wizardp(who))
		return;
#endif

	if(mapp(amount))
	{
		ll = keys(amount);
		for(i=0;i<sizeof(ll);i++)
		{
			
			if( (ll[i] != "gold")
			&& (ll[i] != "silver")
			&& (ll[i] != "coin") )
				continue;

			if(cp_flag)
				switch (ll[i])
				{
					case "gold":
						who->add_credit_point(amount[ll[i]]*10000);
						break;
					case "silver":
						who->add_credit_point(amount[ll[i]]*100);
						break;
					default:
						who->add_credit_point(amount[ll[i]]);
				}
			else
			{
				switch (ll[i])
				{
					case "gold":
						ob = new(GOLD_OB);
						break;
					case "silver":
						ob = new(SILVER_OB);
						break;
					default:
						ob = new(COIN_OB);
				}

				ob->set_amount((int)amount[ll[i]]);
				if(!ob->move(who))
				{
					who->add("save_in_bank/"+ll[i],ob->query_amount());
					destruct(ob);
					flag = 1;
				}
			}
		}

		if(cp_flag)
			return;

		if(flag)
		{
			tell_object(who,"����Ҳ�ò��¸���Ķ�����������Ǯ�Ѿ��浽���������˻����ˡ�\n");
			//who->save();
		}
		return;
	}

	else if(!intp(amount))
		return;

	if(cp_flag)
	{
		who->add_credit_point(amount);
		return;
	}

	g_value = gold_bvalue();
	s_value = silver_bvalue();
	c_value = coin_bvalue();

	v = to_float(amount);
        if (v < c_value)
		return;

        if ( (v / g_value) >= 1 )
	{
                ob = new(GOLD_OB);
                ob->set_amount(to_int(v / g_value));
                if(!ob->move(who))
		{
			flag = 1;
			who->add("save_in_bank/gold",to_int(v / g_value));
			destruct(ob);
		}
                v -= to_int(amount / g_value)*g_value;
        }
        if (v / s_value >= 1)
	{
                ob = new(SILVER_OB);
                ob->set_amount(to_int(v/s_value));
                if(!ob->move(who))
		{
			flag = 1;
			who->add("save_in_bank/silver",to_int(v/ s_value));
			destruct(ob);
		}
                v -= to_int(v / s_value)*s_value;
        }
        if (v/c_value >= 1)
	{
                ob = new(COIN_OB);
                ob->set_amount(to_int(v/c_value));
                if(!ob->move(who))
		{
			flag = 1;
			who->add("save_in_bank/coin",to_int(v / c_value));
			destruct(ob);
		}
        }

	if(flag)
	{
		tell_object(who,"����Ҳ�ò��¸���Ķ�����������Ǯ�Ѿ��浽���������˻����ˡ�\n");
		//who->save();
	}
}

nomask int player_pay(object who, mixed value)
{
        object g_ob, s_ob, c_ob;
        int gc, sc, cc,a_g,a_s,a_c;
	float g_value,s_value,c_value,left,amount;
	int flag = 0;

	g_value = gold_bvalue();
	s_value = silver_bvalue();
	c_value = coin_bvalue();

	if(mapp(value))
	{
		if(a_g = value["gold"])
			amount += a_g * g_value;
		if(a_s = value["silver"])
			amount += a_s * s_value;
		if(a_c = value["coin"])
			amount += a_c * c_value;
	}

	else if(intp(value))
		amount = to_float(value);
	else
		return 0;

	if( (who->query("age") <= PROTECT_AGE) && (who->query_credit_point() >= amount) )
	{
		who->add_credit_point(-abs(to_int(amount)));
		return 3;
	}

        if (g_ob = present("gold_money", who))
	{
		if(!check_money(g_ob,who))
			gc = 0;
		else
                	gc = g_ob->query_amount();
	}
        else
                gc = 0;
        if (s_ob = present("silver_money", who))
	{
		if(!check_money(s_ob,who))
			sc = 0;
		else
                	sc = s_ob->query_amount();
	}
        else
                sc = 0;
        if (c_ob = present("coin_money", who))
	{
		if(!check_money(c_ob,who))
			cc = 0;
                else
			cc = c_ob->query_amount();
	}
        else
                cc = 0;

        if (cc*c_value + sc * s_value + gc * g_value < amount) 
                if (present("thousand-cash", who))
                        return 2;
                else 
                        return 0;
        else
	{
		left = cc*c_value + sc * s_value + gc * g_value - amount;
		if(g_ob)
		{
                	gc = to_int(left / g_value);
                	left -= to_int(left / g_value)*g_value;
		}
		else
			gc = 0;
                sc = to_int(left / s_value);
                cc = to_int((left-to_int(left / s_value)*s_value)/c_value);

		if(gc)
			g_ob->set_amount(gc);
		else if(g_ob)
			destruct(g_ob);

		if(sc)
		{
			if(!s_ob)
				s_ob = new(SILVER_OB);
			s_ob->set_amount(sc);
			if(!s_ob->move(who))
			{
				flag = 1;
				destruct(s_ob);
				who->add("save_in_bank/silver",sc);
			}
                }
		else if(s_ob)
			destruct(s_ob);

		if (cc)
		{
			if(!c_ob)
                        	c_ob = new(COIN_OB);
                        c_ob->set_amount(cc);
			if(!c_ob->move(who))
			{
				flag = 1;
				destruct(c_ob);
				who->add("save_in_bank/coin",cc);
			}
                }
		else if(c_ob)
			destruct(c_ob);

		if(flag)
		{
			tell_object(who,"����Ҳ�ò��¸���Ķ�������������Ǯ�Ѿ��浽���������˻����ˡ�\n");
			//who->save();
		}
                return 1;
        }
}
