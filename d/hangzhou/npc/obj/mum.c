// mum.c

inherit ITEM;

void create()
{
	set_name("Ұ�ջ�", ({ "mum" }) );
	set_weight(100);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "����һ֦������Ұ�ջ���\n");
		set("unit", "֦");
		set("value", 100);
	}
}
