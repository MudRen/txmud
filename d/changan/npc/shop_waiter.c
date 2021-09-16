// shop_waiter.c

#include <ansi.h>

inherit NPC;

void create()
{
	set_name("С���", ({ "huo ji" }) );
	set("gender", "����" );
	set("age", 19);
	set("str",50);
	set("long","��λ�����е�С��ƣ�����һ����ü��
�������ӣ���֪��ʲô���ܵ����顣\n");
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

	switch( random(2) )
	{
	case 0:
		say( CYN"С���Ц�����˵������λ" + RANK_D->query_respect(ob)
			+ "�������ʲôҪ���Ķ�����\n"NOR);
		break;
	case 1:
		say( CYN"С��ƺߺ�ߴߴ˵���������и߼��չ���������Ұ�ޡ���\n"NOR);
		break;
	}
}
