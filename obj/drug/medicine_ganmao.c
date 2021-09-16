// medicine_ganmao.c
// Find.

inherit ITEM;

void create()
{
	set_name("��ðҩ", ({ "cold medicine", "medicine" }) );
	set_weight(50);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ��ר��ҽ�θ�ð���յ�ҩƷ��\n");
		set("value", 100);
	}
}

void init()
{
	add_action("do_eat",({ "eat","fu" }));
}

int do_eat(string arg)
{
	object me = this_player();

	if( !arg || !id(arg) )
		return 0;

	if(environment() != me)
		return 0;

	write("�����һ����ðҩ��");
	if(!me->query_condition("ganmao"))
	{
		write("����ζ����һ��ࡣ\n");
		destruct(this_object());
		return 1;
	}

	me->apply_condition("ganmao",1);
	write("��������ö��ˡ�\n");
	destruct(this_object());
	return 1;
}