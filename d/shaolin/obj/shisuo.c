// shisuo.c

inherit ITEM;

void create()
{
	set_name("ʯ��", ({ "shi suo", "suo" }) );

	set_weight(100);

	if( clonep() )
		set_default_object(__FILE__);
	else
	{
		set("unit", "��");
		set("no_get",1);
		set("long", "����һ�������º��������õ�ʯ\n������Ҳ���Ծ�(ju)һ�����ԡ�\n");
	}
	setup();
}

void init()
{
	add_action("do_ju","ju");
}

int do_ju(string arg)
{
	object me = this_player();
	string who;
	int damage,skill;

	if(!arg || !id(arg))
		return notify_fail("��Ҫ��ʲô��\n");

	if(who = query_temp("do_ju"))
		return notify_fail(who+"���ھ����ʯ�������һ�°ɡ�\n");

	damage = (int)me->query("age")/2 + 3;
	if(me->query("kee") < damage)
		return notify_fail("������������֧����������Ϣһ����˵�ɡ�\n");
	set_temp("do_ju",me->name());
	if( (skill = (int)me->query_skill("unarmed",1)) >80)
		message_vision("$N����һ���������ɵؽ�ʯ���ٹ�ͷ����\n",me);
	else
		message_vision("$Nһҧ����ʯ�������ٹ�ͷ����\n",me);
	me->start_busy(3);
	call_out("do_drop",2,me,damage,skill);
	return 1;
}

void do_drop(object me,int damage,int skill)
{
	int str = me->query("str");
	int improve;

	if(str > 30)
		str = 30;

	improve = str/2 + random(str/2);
	message_vision("$N��ʯ�������˵��ϡ�\n",me);
	delete_temp("do_ju");
	me->receive_damage("kee",damage,"tire");

	if(skill < 40)
		me->improve_skill("unarmed",improve);
	if(me->query("combat_exp") < 20000)
		me->add("combat_exp",random(20));
	me->stop_busy();
}