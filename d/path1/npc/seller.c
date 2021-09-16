// seller.c

inherit F_DEALER;

void create()
{
	set_name("小商贩", ({ "seller" }) );
	set("gender", "男性" );
        set("age", 37);
        set("long","这是一位正在大喊大叫着招揽生意的小贩。\n");
        set("combat_exp", 50);
        set("attitude", "friendly");
	set("sell_all_day",1);

	set("vendor_goods", ([
		FOOD_DIR"dumpling":-1,
		__DIR__"obj/waterskin":-1,
	]) );

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

	say(sprintf("%s吆喝道：“前面路很长这位%s卖点吃喝带上吧。”\n",name(),RANK_D->query_respect(ob)));
}