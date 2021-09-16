// waiter_1.c

#include <ansi.h>

inherit NPC;

void create()
{
	set_name("��С��", ({ "xiao er" }) );
	set("gender", "����" );
	set("age", 20);
	set("str",50);
	set("long",
		"��λ��С����Ц�����æ��������ʱ������ڲ����ϵ�Ĩ��������\n");
	set("combat_exp", 100);
	set("attitude", "friendly");
	setup();
	carry_object(ARMOR_DIR"cloth")->wear();
}

void init()
{	
	object ob;

	::init();
	if( interactive(ob = previous_object()) && !is_fighting() )
	{
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
}

void greeting(object ob)
{

	if( !ob
	|| (environment(ob) != environment())
	|| file_name(environment()) != this_object()->query("startroom"))
		return;

	if(!userp(ob) && ob->query("is_beggar"))
	{
		message_vision(CYN"$N����$n˵������⵰Ҳ��ס�꣬�Ͻ�����\n"NOR,this_object(),ob);
		ob->go_back_direction();
		return;
	}

	switch( random(4) )
	{
	case 0:
		say( CYN"��С��Ц�����˵������λ" + RANK_D->query_respect(ob)
			+ "�������ȱ��裬ЪЪ�Ȱɡ�\n"NOR);
		break;
	case 1:
		say( CYN"��С���ò����ϵ�ë��Ĩ��Ĩ�֣�˵������λ" + RANK_D->query_respect(ob)
			+ "����������\n"NOR);
		break;
	}
}

int accept_object(object who, object ob)
{
	if ( is_money(ob) && ob->value() >= 100) 
	{
		tell_object(who, "С��һ������˵������л���ϣ��͹�����¥ЪϢ��\n");
		who->set_temp("rent_paid",1);
		return 1;
	}

	else
	{
		tell_object(who, "С��ҡҡͷ˵����ס��һ��һ�����ӣ�������ѸŲ���Ƿ��\n");
			return 0;
	}
}