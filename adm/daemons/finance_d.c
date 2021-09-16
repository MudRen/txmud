//	/adm/daemons/finance_d.c
// 一些因素会影响货币的比值,如银行存款,如一种货币存量变高相应就要贬值.
// 玩家银行存款记录改为mapping, gold silver coin三种货币分别记录.
// F_FINANCE player_pay 函数要能区分货币种类.
//           pay_player 函数找给玩家的货币要优先选择比价低的货币种类.
// F_DEALER list 物品的价格应该区分货币.
// BANK huan 要进行比价换算,要收取手续费.

/* 返回当前金、银、铜的单位价值 */
nomask float base_gold_value()
{
	return 10000.00;
}

nomask float base_silver_value()
{
	return 100.00;
}

nomask float base_coin_value()
{
	return 1.00;
}

nomask float base_cash_value()
{
	return 1000*base_silver_value();
}

/* 商品价格区分三级，每级差为 5% ，相关物件 dealer shop hockshop.*/
nomask int price_domain(object env /* room object. */)
{
/*****************************************
 * 一级重镇，如：长安、奉天，为 100。      *
 * 二级区域，普通城镇，为 95。             *
 * 三级区域，如：普通村落、偏远地区，为 90。*
 ******************************************/
	string domain;

	if(!env)
		return 100;

	if(!sscanf(file_name(env), "/d/%s/%*s", domain))
		return 100;

	else
		return 100;
}