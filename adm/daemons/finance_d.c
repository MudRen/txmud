//	/adm/daemons/finance_d.c
// һЩ���ػ�Ӱ����ҵı�ֵ,�����д��,��һ�ֻ��Ҵ��������Ӧ��Ҫ��ֵ.
// ������д���¼��Ϊmapping, gold silver coin���ֻ��ҷֱ��¼.
// F_FINANCE player_pay ����Ҫ�����ֻ�������.
//           pay_player �����Ҹ���ҵĻ���Ҫ����ѡ��ȼ۵͵Ļ�������.
// F_DEALER list ��Ʒ�ļ۸�Ӧ�����ֻ���.
// BANK huan Ҫ���бȼۻ���,Ҫ��ȡ������.

/* ���ص�ǰ������ͭ�ĵ�λ��ֵ */
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

/* ��Ʒ�۸�����������ÿ����Ϊ 5% �������� dealer shop hockshop.*/
nomask int price_domain(object env /* room object. */)
{
/*****************************************
 * һ�������磺���������죬Ϊ 100��      *
 * ����������ͨ����Ϊ 95��             *
 * ���������磺��ͨ���䡢ƫԶ������Ϊ 90��*
 ******************************************/
	string domain;

	if(!env)
		return 100;

	if(!sscanf(file_name(env), "/d/%s/%*s", domain))
		return 100;

	else
		return 100;
}