// shadai.c

inherit ITEM;

string master;

void create()
{
	set_name("ɳ��", ({ "sha dai" }) );

	set_weight(100);

	if( clonep() )
		set_default_object(__FILE__);
	else
	{
		set("unit", "��");
		set("no_get",1);
		set("long", "����һ����ɳ���λ����Ƶĵ�������
��׳�������м䡣��ɽ���Ӵ󲿷ֶ�
�ǴӴ�(da)ɳ����ʼ��ϰȭ�ŵġ�\n");
	}
	setup();
}

void init()
{
	add_action("do_hit","da");
}

int do_hit(string arg)
{
	object me = this_player();
	int damage,skill;

	if(!arg || !id(arg))
		return notify_fail("��Ҫ��ʲô��\n");

	if(master)
		return notify_fail(master+"���ڴ����ɳ�������һ�°ɡ�\n");

	damage = (int)me->query("age")/2;

	if(me->query("kee") < damage)
		return notify_fail("������������֧����������Ϣһ����˵�ɡ�\n");

	master = me->name();

	skill = me->query_skill("unarmed",1);
	message_vision("$N����һ����������$n�ݺݵĴ��˹�ȥ��\n",me,this_object());

	me->start_busy(4);
	call_out("do_finish",2,me,damage,skill);
	return 1;
}

private void do_finish(object me,int damage,int skill)
{
	int str,improve;

	master = 0;

	if(!me || (environment(me) != environment()))
		return;

	if(skill > 50)
		tell_object(me,"ɳ���������ϸߣ�������ͣ��������\n");
	else
	{
		if((str = me->query("str")) > 30)
			str = 30;
	
		if(skill <= 10)
			skill += 15;
		else if(skill <= 20)
			skill += 10;
		else
			skill += 5;
	
		if(random(skill) < 5)
		{
			if(!random(3))
			{
				message_vision("ɳ���ƻ���ײ��$Nһ����������\n",me);
				me->receive_damage("kee",damage/2);
				return;
			}
			else
			{
				tell_object(me,"ɳ�����һ���һ�£�ûʲô��Ӧ��\n");
				me->stop_busy();
				me->receive_damage("kee",damage/2);
				return;
			}
		}

		improve = str/2 + random(str/2);
		tell_object(me,"ɳ��ǰ�����˼��£�������ͣ��������\n");
		me->receive_damage("kee",damage,"tire");

		me->improve_skill("unarmed",improve);
	}

	if(me->query("combat_exp") < 30000)
		me->add("combat_exp",random(20));
	me->stop_busy();
}
