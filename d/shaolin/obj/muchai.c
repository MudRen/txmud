// muchai.c

inherit COMBINED_ITEM;

void create()
{
	set_name("木柴", ({"mu chai"}));
	if( clonep() )
		set_default_object(__FILE__);
	else
	{
		set("long","这是烧火做饭用的木柴。\n");
		set("unit", "些");
		set("base_unit", "根");
		set("base_weight", 10);
	}
	set_amount(1);
}
