// thousand.c

inherit MONEY;

void create()
{
	set_name("һǧ����Ʊ", ({"thousand-cash", "thousand-cash_money", "cash"}));
	if( clonep() )
		set_default_object(__FILE__);
	else
	{
		set("money_id", "thousand-cash");
		set("long", "һ�����ֵһǧ�����ӵ���Ʊ��\n");
		set("unit", "��");
		set("base_value", (: call_other(FINANCE_D, "base_cash_value") :) );
		set("base_unit", "��");
		set("base_weight", 10);
	}
	set_amount(1);
}