// douya.c

inherit ITEM;

void create()
{
	set_name("��ѿ��", ({ "bean" }) );
	set_weight(100);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "����һ�����ʵĶ�ѿ�ˡ�\n");
		set("unit", "��");
		set("value", 50);
	}
}
