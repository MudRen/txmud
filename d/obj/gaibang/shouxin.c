// ؤ������
// edit by pian

inherit ITEM;

void create()
{
	set_name("��ؤ�����š�", ({ "gaibang shouxin" }) );
	set_weight(500);
	
	if( clonep() )
		set_default_object(__FILE__);
	else
	{
		set("long", "    һ��ؤ����鱨�š�\n");
		set("unit", "��");
		set("value", 10);
	}
}