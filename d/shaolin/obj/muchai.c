// muchai.c

inherit COMBINED_ITEM;

void create()
{
	set_name("ľ��", ({"mu chai"}));
	if( clonep() )
		set_default_object(__FILE__);
	else
	{
		set("long","�����ջ������õ�ľ��\n");
		set("unit", "Щ");
		set("base_unit", "��");
		set("base_weight", 10);
	}
	set_amount(1);
}
