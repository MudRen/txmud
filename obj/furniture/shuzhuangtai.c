// shuzhuangtai.c

inherit ITEM;

void create()
{
	set_name("��ľ��ױ̨", ({ "shuzhuang tai" }) );

	set_weight(300);

	if( clonep() )
		set_default_object(__FILE__);
	else
	{
		set("no_get",1);
		set("unit", "��");
		set("long", "����һ����ľ��ױ̨��̨�ϻ���һ��ͭ����\n");
		set("value", 100000);
		set("material", "wood");
	}
	setup();
}