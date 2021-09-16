// shop_waiter.c

#include <ansi.h>

inherit NPC;

void create()
{
	set_name("小伙计", ({ "huo ji" }) );
	set("gender", "男性" );
	set("age", 19);
	set("str",50);
	set("long","这位是商行的小伙计，看他一付愁眉苦
脸的样子，不知有什么难受的事情。\n");
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
		say( CYN"小伙计笑咪咪地说道：这位" + RANK_D->query_respect(ob)
			+ "请进，有什么要卖的东西吗？\n"NOR);
		break;
	case 1:
		say( CYN"小伙计哼哼叽叽说道：“本行高价收购各种珍禽野兽。”\n"NOR);
		break;
	}
}
