// gold.c

#include <ansi.h>

inherit MONEY;

void create()
{
	set_name(HIY"�ƽ�"NOR, ({"gold", "ingot", "gold_money"}));
	if( clonep() )
		set_default_object(__FILE__);
	else
	{
		set("money_id", "gold");
		set("long", "�ƳγεĽ��ӣ��˼��˰��Ľ��ӣ����������ӣ�\n");
		set("unit", "Щ");
		set("base_value", (: call_other(FINANCE_D, "base_gold_value") :) );
		set("base_unit", "��");
		set("base_weight", 100); // һ������ 100.
	}
	set_amount(1);
}