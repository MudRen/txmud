// gold.c

#include <ansi.h>

inherit MONEY;

void create()
{
	set_name(HIY"黄金"NOR, ({"gold", "ingot", "gold_money"}));
	if( clonep() )
		set_default_object(__FILE__);
	else
	{
		set("money_id", "gold");
		set("long", "黄澄澄的金子，人见人爱的金子，啊～～金子！\n");
		set("unit", "些");
		set("base_value", (: call_other(FINANCE_D, "base_gold_value") :) );
		set("base_unit", "两");
		set("base_weight", 100); // 一两就是 100.
	}
	set_amount(1);
}