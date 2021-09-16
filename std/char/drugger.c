//	/std/char/drugger.c
// ҩ����ϰ壬�չ���Ʒ���
// drugger ԭ��Ϊ�����ߣ��Լ�����Ϊ���ɶ�Ʒ���ˡ�
// ��֪��������ʲô�����Ľз�������������ˡ�
// by Find.

inherit F_DEALER;

void init()
{
	::init();
	add_action("do_sell","sell");
}

int do_sell(string arg)
{
	object ob,me = this_player();
	int value;

	if(!environment())
		return 0;

	if(!is_day())
	{
		command("say ����������������ɡ�");
		return 1;
	}

	if(!stringp(arg) || !ob=present(arg,me))
		return notify_fail("��Ҫ��ʲô��\n");

	if(!ob->is_poison())
		return notify_fail("������ֻ�չ���Ʒ�Ķ���������ҩ��ԭ�ϡ�\n");

	if((int)ob->query("can_use") < 1)
		return notify_fail("���"+ob->name()+"�Ѿ�û��һ�㶾���ˣ�һ�Ĳ�ֵ��\n");

	if(!value = ob->query("value"))
		value = ob->value();
	if(!value)
		return notify_fail("���"+ob->name()+"����̫С�ˣ�һ�Ĳ�ֵ��\n");

	value = value*price_ratio(environment())/100;
	if(value < 1)
		value = 1;

	write(sprintf("���%s�������õ�%s��\n",ob->name(),chinese_value(value)));
	pay_player(me,value);
	destruct(ob);
	return 1;
}