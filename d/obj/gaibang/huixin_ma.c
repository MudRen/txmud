// 马长老的回信
// edit by pian

inherit ITEM;

void create()
{
	set_name("『马长老的回信』", ({ "hui xin" }) );
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