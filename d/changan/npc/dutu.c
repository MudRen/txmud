// dutu.c

inherit NPC;

void create()
{
	set_name("��ͽ", ({ "du tu" }) );
	set("gender", "����" );
	set("age", 38);

	set("long", "����һλ����þ���Ķ�ͽ��\n");

	set("combat_exp", 5000);
	set("per",20);
	set("str", 27);
	set("force", 200);
	set("max_force", 200);
	set("force_factor", 2);
	set_skill("unarmed",50);

	setup();

	carry_object(ARMOR_DIR"cloth")->wear();
}

int accept_fight(object me)
{
	command("say ���Ӹ����һ���ֶ�Ҳû���ˣ�����������䣡��\n");
	return 0;
}
 
void init()
{
	object ob;

	::init();
	if (interactive(ob = this_player()) && !is_fighting())
	{
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
}
 
void greeting(object ob)
{
	if(!ob || environment(ob) != environment())
		return;

	command(sprintf("look %s",ob->query("id")));
	command(sprintf("say ��λ%s�ܲ��ܽ輸���������ã���",RANK_D->query_respect(ob)));
}

int accept_object(object me, object ob)
{
	if(!ob->query("money_id"))
		return 0;

	if(ob->value() < 100000)
	{
		command("say ��л��λ" + RANK_D->query_respect(me) + "������Ӯ��һ���ӱ����㣡");
		call_out("do_destruct",1,ob);
		return 1;
	}

	call_out("do_point",2,me,ob);
	return 1;
}

void do_destruct(object ob)
{
	if(objectp(ob))
		destruct(ob);
}

private void do_point(object me,object ob)
{
	if(!me || environment(me) != environment() || !living(me))
		return;

	message_vision("$N��ͨһ������$n��ǰ˵�����������ҵ�������ĸ��������\n������Ǯ���Ⱳ��Ҳ����������\n\n",
		this_object(),me);

	command(sprintf("tell %s ������֪��һ�����ܸ������͵������ɡ����������ɽ����һ
                   ��������կ�������ڷ���ͤ����һ������һ���򱱵�·һֱ
                   �����߾͵��ˣ������Ǹ�ɱ�˲�գ�۵������̾�ĵط����ǳ�
                   Σ�գ�����կ�ĺ�ɽ��һλ�������������������������
                   ʱ����һλ�Ĺ����֡�",me->query("id")));

	me->set_temp("pass_changan_dutu",1);
	if(ob)
		call_out("do_destruct",1,ob);
}
