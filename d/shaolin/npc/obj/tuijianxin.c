// tuijianxin.c

inherit ITEM;

void create()
{
	set_name("推荐信", ({ "tuijian xin", "xin" }) );

	set_weight(100);

	if( clonep() )
		set_default_object(__FILE__);
	else
	{
		set("unit", "封");
		set("long", "这是一封普通的信件。\n");
	}
	setup();
}