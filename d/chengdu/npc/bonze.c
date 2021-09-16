// bonze.c

inherit NPC;

void create()
{
        set_name("老和尚", ({ "old bonze","bonze" }) );
        set("gender", "男性" );
        set("age", 68);
        set("long",
                "他已经在宝光寺呆了几十年了。\n");
        set("combat_exp", 20);

        set_skill("literate",1);
        set("attitude", "friendly");
        setup();
        carry_object(ARMOR_DIR"cloth")->wear();
}

void init()
{       
	object ob;

	::init();
	if( interactive(ob = this_player()) && !is_fighting() ) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
}

void greeting(object ob)
{
	if( !ob || !present(ob, environment(this_object())) )
		return;

	say( "老和尚说道：这位" + RANK_D->query_respect(ob)
		+ "，捐点香火钱积点阴德吧。\n");
}

int accept_object(object who, object ob)
{
	int val;

	if(!is_money(ob))
		return notify_fail("庙祝不收物品的捐献。\n");

	if( (val = ob->value()) >= 100 )
	{
		if( who->query("bellicosity") > 0 )
			who->add("bellicosity", - to_int((random(who->query("kar")) + val/100)) );
	}
	say( "老和尚说道：多谢这位" + RANK_D->query_respect(who)
		+ "，神明一定会保佑你的。\n");

        return 1;
}
