// shuzhuangtai.c

inherit ITEM;

void create()
{
	set_name("红木梳妆台", ({ "shuzhuang tai" }) );

	set_weight(300);

	if( clonep() )
		set_default_object(__FILE__);
	else
	{
		set("no_get",1);
		set("unit", "付");
		set("long", "这是一付红木梳妆台，台上还有一面铜镜。\n");
		set("value", 100000);
		set("material", "wood");
	}
	setup();
}