// /adm/simul_efun/bank.c
// By find.

nomask float gold_bvalue()
{
	return FINANCE_D->base_gold_value();
}

nomask float silver_bvalue()
{
	return FINANCE_D->base_silver_value();
}

nomask float coin_bvalue()
{
	return FINANCE_D->base_coin_value();
}

nomask float gtos_ratio()
{
	return FINANCE_D->base_gold_value()/FINANCE_D->base_silver_value();
}

nomask float gtoc_ratio()
{
	return FINANCE_D->base_gold_value()/FINANCE_D->base_coin_value();
}

nomask float stoc_ratio()
{
	return FINANCE_D->base_silver_value()/FINANCE_D->base_coin_value();
}

/*
int pay_from_bank(object me,int value,int flag)
{
	mapping save_in_bank;
	int gold,silver,coin;
	float g_v,s_v,c_v;

	if(!me)
		return 0;
	if(!value)
		return 1;
	save_in_bank = me->query("save_in_bank");

	gold = save_in_bank["gold"];
	if(gold)
	{
		g_v = gold*gold_bvalue();
		if(g_v <= value)
		{
			gold = 0;
			value -= to_int(g_v);
		}

		else if( g_v > value )
		{
			if(!flag)
			{
			me->set("save_in_bank/gold",to_int((g_v-value)/gold_bvalue()) );
			me->pay_player(me,to_int(g_v-value-me->query("save_in_bank/gold")*gold_bvalue()));
			me->save();
			}
			return 1;
		}
	}

	silver = save_in_bank["silver"];
	if(silver && value)
	{
		s_v = silver*silver_bvalue();
		if(s_v <= value)
		{
			silver = 0;
			value -= to_int(s_v);
		}

		else if( s_v > value )
		{
			if(!flag)
			{
			me->set("save_in_bank/gold",gold);
			me->set("save_in_bank/silver",to_int((s_v-value)/silver_bvalue()) );
			me->pay_player(me,to_int(s_v-value-me->query("save_in_bank/silver")*silver_bvalue()));
			me->save();
			}
			return 1;
		}
	}

	coin = save_in_bank["coin"];
	if(coin && value)
	{
		c_v = coin*coin_bvalue();
		if(c_v <= value)
		{
			coin = 0;
			value -= to_int(c_v);
		}

		else if( c_v > value )
		{
			if(!flag)
			{
			me->set("save_in_bank/gold",gold);
			me->set("save_in_bank/silver",silver);
			me->set("save_in_bank/coin",to_int((c_v-value)/coin_bvalue()) );
			me->save();
			}
			return 1;
		}
	}

	return 0;
}
*/

nomask int save_to_bank(object me,int pay)
{
	int gold,silver,coin,g,s,c,MAX = 2000000000;
	float remain;

	if(!me || !pay)
		return 0;

	gold = to_int(pay/FINANCE_D->base_gold_value());
	remain = pay - (gold*FINANCE_D->base_gold_value());

	silver = to_int(remain/FINANCE_D->base_silver_value());
	remain -= silver*FINANCE_D->base_silver_value();

	coin = to_int(remain/FINANCE_D->base_coin_value());

	g = me->query("save_in_bank/gold");
	s = me->query("save_in_bank/silver");
	c = me->query("save_in_bank/coin");

	if( gold > (MAX - g) )
	{
		tell_object(me,"��������治����ô��Ǯ�ˡ�\n");
		return 0;
	}
	if( silver > (MAX - s) )
	{
		tell_object(me,"��������治����ô��Ǯ�ˡ�\n");
		return 0;
	}
	if( coin > (MAX - c) )
	{
		tell_object(me,"��������治����ô��Ǯ�ˡ�\n");
		return 0;
	}

	me->add("save_in_bank/gold",gold);
	me->add("save_in_bank/silver",silver);
	me->add("save_in_bank/coin",coin);
	//me->save();

	return 1;
}

/* if return 0 means can not pay from bank,1 payed from bank */
/* ��� flag Ϊ 1, ֻ�����жϲ� pay,
return 0 û������֧��
return 1 ������֧�� */
/* �����ֵ��������ִ��� 2^32 ����� */
nomask int pay_from_bank(object me,int value,int flag)
{
	int g,s,c,temp;
	int g_bank,s_bank,c_bank;

	if(!me)
		return 0;
	if(value <= 0)
		return 1;

	g_bank = (int)me->query("save_in_bank/gold");
	s_bank = (int)me->query("save_in_bank/silver");
	c_bank = (int)me->query("save_in_bank/coin");

	g = value/10000;
	value -= g*10000;

	s = value/100;
	value -= s*100;

	c = value;

	temp = g_bank-g;
	if(temp < 0)
	{
		g = -temp;
		g_bank = 0;
	}
	else
	{
		g_bank = temp;
		g = 0;
	}

	s += g*100;
	temp = s_bank-s;
	if(temp  < 0)
	{
		if(g_bank)
		{
			g_bank--;
			s_bank += 100;
			temp = s_bank - s;
			s_bank = temp;
			s = 0;
		}
		else
		{
			s = -temp;
			s_bank = 0;
		}
	}
	else
	{
		s_bank = temp;
		s = 0;
	}

	c += s*100;
	temp = c_bank-c;
	if(temp  < 0)
	{
		if(s_bank)
		{
			s_bank--;
			c_bank += 100;
			temp = c_bank-c;
			c_bank = temp;
			c = 0;
		}
		else
			//c = -temp;
			//c_bank = 0;
			return 0;
	}
	else
	{
		c_bank = temp;
		c = 0;
	}

	if(c)
		return 0;
	else
	{
		if(!flag)
		{
			me->set("save_in_bank/gold",g_bank);
			me->set("save_in_bank/silver",s_bank);
			me->set("save_in_bank/coin",c_bank);
			me->save();
		}
		return 1;
	}
}
