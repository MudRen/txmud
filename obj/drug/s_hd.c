// s_hd.c
// �޸� 50 �������ޡ�

// Find.

inherit ITEM;

void create()
{
	set_name("С����", ({ "xiao hd", "huandan" }) );
	set_weight(50);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ������С������ר�ε������ˡ�\n");
		set("value", 1500);
	}
}

void init()
{
	add_action("do_eat",({ "eat","fu" }));
}

int do_eat(string arg)
{
	object me = this_player();
	int max_k,eff_k,add;

	if( !arg || !id(arg) )
		return 0;

	if(environment() != me)
		return 0;

	max_k = me->query("max_kee");
	eff_k = me->query("eff_kee");

	add = ((max_k - eff_k) > 50)?50:(max_k - eff_k);

	if(!add)
	{
		write("�����һ��С����������ûʲô��Ӧ��\n");
		destruct(this_object());
		return 1;
	}

	me->add("eff_kee",add);

	write("�����һ��С�������������ϵ��˿ڿ�ʼ�����������ˡ�\n");
	destruct(this_object());
	return 1;
}