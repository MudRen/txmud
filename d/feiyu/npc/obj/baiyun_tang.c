// baiyun_tang.c

inherit ITEM;

void create()
{
	set_name("������", ({ "baiyun tang" }) );

	set_weight(100);

	if( clonep() )
		set_default_object(__FILE__);
	else
	{
		set("long", "����һ���غ�ɫ�İ�������\n");
		set("unit", "��");
		set("value", 1);
	}
}
