// lian_zi.c

inherit ITEM;

void create()
{
	set_name("����", ({ "lian zi" }) );

	set_weight(100);

	if( clonep() )
		set_default_object(__FILE__);
	else
	{
		set("long", "����һ����Ƥ�����ӡ�\n");
		set("unit", "��");
		set("value", 1);
	}
}
