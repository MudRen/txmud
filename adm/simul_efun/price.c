// /adm/simul_efun/price.c
// by Find.

/* ȡ env ���ڵ��������ָ�� */
nomask int price_ratio(object env)
{
	return 	FINANCE_D->price_domain(env);
}

/* ȡ����ļ�ֵ */
int query_ride_value(object ride)
{
	int value,level;
	int *price = ({5000,5500,6000,8000,10000,12000,18000,22000,40000,50000});

	if(!objectp(ride) || !ride->is_character() || !ride->query("ride"))
		return 0;

	if(!undefinedp(ride->query("value")))
		value = ride->query("value");
	else
	{
		level = ride->query("ride_level");
		if(level > 10)
			level = 10;
		if(level < 1)
			level = 1;
		value = price[level-1];
	}
	return value;
}