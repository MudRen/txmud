// liujinfeng.c

#include <ansi.h>

inherit F_DEALER;

void create()
{
	set_name("刘金风", ({ "liu jinfeng","boss" }) );
	set("title","杂货铺老板");
        set("gender", "男性" );
        set("age", 42);
	set("sell_all_day",1);
        set("long","这是一位瘦小枯干的中年人。\n");
        set("combat_exp", 50);
        set("attitude", "friendly");
        set("vendor_goods", ([
		MISC_DIR"bag":20,
		MISC_DIR"lamp":5,
		MISC_DIR"torch":20,
		"/obj/mine/sz_gao" : 80,
        ]) );
        setup();
	carry_object(ARMOR_DIR"cloth")->wear();
}

void init()
{
        object ob;

	::init();
        if( living(ob = previous_object()) && !is_fighting() )
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

	switch( random(2) )
	{
		case 0:
			say( CYN"刘金风说道：这位" + RANK_D->query_respect(ob)
				+ "，请进请进。\n"NOR);
			break;
		case 1:
			say( CYN"刘金风说道：这位" + RANK_D->query_respect(ob)
				+ "要买点什么？\n"NOR);
			break;
	}
}
