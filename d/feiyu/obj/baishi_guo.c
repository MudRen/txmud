// baishi_guo.c

inherit ITEM;

void create()
{
	set_name("��ʵ��", ({ "baishi guo" }) );
	set_weight(100);
	if( clonep() )
		set_default_object(__FILE__);
	else
	{
		set("long", "����һö��ʵ����\n");
		set("unit", "ö");
		set("value", 1);
	}
}
