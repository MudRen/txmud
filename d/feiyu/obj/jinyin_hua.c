// jinyin_hua.c

inherit ITEM;

void create()
{
	set_name("金银花", ({ "jinyin hua" }) );
	set_weight(100);
	if( clonep() )
		set_default_object(__FILE__);
	else
	{
		set("long", "这是一朵金银花。\n");
		set("unit", "朵");
		set("value", 1);
	}
}
