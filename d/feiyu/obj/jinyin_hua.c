// jinyin_hua.c

inherit ITEM;

void create()
{
	set_name("������", ({ "jinyin hua" }) );
	set_weight(100);
	if( clonep() )
		set_default_object(__FILE__);
	else
	{
		set("long", "����һ���������\n");
		set("unit", "��");
		set("value", 1);
	}
}
