// waiter.c

#include <ansi.h>

inherit NPC;

void create()
{
	set_name("店小二", ({ "waiter" }) );
	set("gender", "男性" );
	set("age", 20);
	set("str",50);
	set("long", "这位店小二正笑咪咪地忙著，还不时拿起挂在
脖子上的抹布擦脸。\n");
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
		message_vision(CYN"$N冲着$n说道：穷光蛋也想住店，赶紧滚！\n"NOR,this_object(),ob);
		ob->go_back_direction();
		return;
	}

	switch( random(2) )
	{
	case 0:
		say( CYN"店小二笑咪咪地说道：这位" + RANK_D->query_respect(ob)
			+ "，进来喝杯茶，歇歇腿吧。\n"NOR);
		break;
	case 1:
		say( CYN"店小二用脖子上的毛巾抹了抹手，说道：这位" + RANK_D->query_respect(ob)
			+ "，请进请进。\n"NOR);
		break;
	}
}

int accept_object(object who, object ob)
{
	if(is_money(ob) && ob->value() >= 100)
	{
		tell_object(who, "小二一哈腰，说道：多谢您老，客官请上楼歇息。\n");
		who->set_temp("rent_paid",1);
		return 1;
	}

	else
	{
		tell_object(who, "小二摇摇头说道：住店一晚一两银子，亲朋好友，概不赊欠。\n");
			return 0;
	}
}
