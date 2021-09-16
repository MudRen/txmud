// huntun.c

inherit ITEM;

void create()
{
        set_name("���", ({"hun tun"}));
        set("long", "����һ���������ڵ���⽡�\n");
        set("unit", "��");
        set("weight", 800);
        set("value", 100);
}

void init()
{
	if(environment() && userp(environment()) && !query("begin"))
	{
		add_action("do_eat",({ "he", "eat" }));
		call_out("do_decay",240,0);
		set("begin",1);
	}
}

int do_eat(string arg)
{
	object me = this_player();

	if(environment() != me)
		return 0;

	if(!stringp(arg) || !id(arg))
		return 0;

	if(me->query("food") >= me->max_water_capacity())
		return notify_fail("���Ѿ���̫���ˣ���Ҳ�������κζ����ˡ�\n");

	if(query("decayed"))
	{
		message_vision("$N����һ����⽸�Ҫ�ȷ����Ѿ������ˣ�$N���ְ���������˵��ϡ�\n",me);
		destruct(this_object());
		return 1;
	}
	me->add("food",80);
	me->add("water",30);

	message_vision("$N����һ�������������ĺ�����ȥ��\n",me);
	destruct(this_object());
	return 1;
}

void do_decay(int n)
{
	remove_call_out("do_decay");
	if(!n)
	{
		set("long", "����һ���Ѿ��ŵı�������⽡�\n");
		call_out("do_decay",300,1);
		return;
	}

	else
	{
		set("long", "����һ���Ѿ������˵���⽡�\n");
		set("decayed",1);
		return;
	}
}
