// tuijianxin.c

inherit ITEM;

void create()
{
	set_name("�Ƽ���", ({ "tuijian xin", "xin" }) );

	set_weight(100);

	if( clonep() )
		set_default_object(__FILE__);
	else
	{
		set("unit", "��");
		set("long", "����һ����ͨ���ż���\n");
	}
	setup();
}