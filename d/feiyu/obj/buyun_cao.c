// buyun_cao.c

inherit ITEM;

void create()
{
	set_name("���Ʋ�", ({ "buyun cao" }) );
	set_weight(100);
	if( clonep() )
		set_default_object(__FILE__);
	else
	{
		set("long", "����һ�Ų��Ʋݡ�\n");
		set("unit", "��");
		set("value", 1);
	}
}
