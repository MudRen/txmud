// tao.c ɽ��
// �������������4��

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("��ɽ��", ({ "shan tao" }) );
	set_weight(80);

	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long","һֻ��ɫ��ɽ�ҡ��ǻ�ɽ���ز���\n");
		set("unit", "ֻ");
		set("food_remaining", 3);
		set("food_supply", 30);
	}
}

void init()
{
	if(environment() && userp(environment()) && (find_call_out("do_decay") == -1))
		call_out("do_decay",90);
	add_action("do_eat","eat");
}

int do_eat(string arg)
{
	object me = this_player();

	if(!arg || !id(arg))
		return notify_fail("��Ҫ��ʲô��\n");

	message_vision("$Nץ����ɽ�ҷ�������������ڵľͳ����ˡ�\n",me);
	write("��ֻ����������Ѫ��ײ��һ�������ӵ�������ɢ����֫��\n");
	me->add("max_force",5);
	destruct(this_object());
	return 1;
}

protected void do_decay()
{
	if(environment())
		tell_object(environment(),"��ɽ�ҷŵ�ʱ��̫�����õ��ˡ�\n");
	destruct(this_object());
}
