// 丐帮手信
// edit by pian

inherit ITEM;

void create()
{
	set_name("『丐帮手信』", ({ "gaibang shouxin" }) );
	set_weight(500);
	
	if( clonep() )
		set_default_object(__FILE__);
	else
	{
		set("long", "    一封丐帮的情报信。\n");
		set("unit", "封");
		set("value", 10);
	}
}