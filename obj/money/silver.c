// silver.c

#include <ansi.h>

inherit MONEY;

void create()
{
	set_name(HIW"����"NOR, ({"silver", "ingot", "silver_money"}));
	if( clonep() )
		set_default_object(__FILE__);
	else
	{
		set("money_id", "silver");
		set("long", "�׻��������ӣ��˼��˰������ӡ�\n");
		set("unit", "Щ");
		set("base_value", (: call_other(FINANCE_D, "base_silver_value") :));
		set("base_unit", "��");
		set("base_weight", 100);
	}
	set_amount(1);
}
