// baicai.c

inherit ITEM;

void create()
{
	set_name("��ײ�", ({ "cabbage" }) );
	set_weight(100);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "����һ�������Ĵ�ײˡ�\n");
		set("unit", "��");
		set("value", 50);
	}
}
