// qincai.c

inherit ITEM;

void create()
{
	set_name("�۲�", ({ "celery" }) );
	set_weight(100);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "����һ���������۲ˡ�\n");
		set("unit", "��");
		set("value", 50);
	}
}
