// weaponboss.c

inherit F_DEALER;

void create()
{
	set_name("兵器铺老板", ({ "weapon boss", "boss" }) );
	set("gender", "男性" );
	set("age", 40);

	set("long", "兵器铺老板个脸上有一道伤疤中年人，
一笑起来份外诡异。\n");

	set("combat_exp", 30000);
	set("attitude", "friendly");
	set("max_kee",1000);
	set("max_force",1000);
	set("force_factor",20);

	set_skill("unarmed", 100);
	set_skill("dodge", 100);
	set_skill("sword", 100);
	set_skill("parry", 120);

	set("sell_all_day",1);

	set("inquiry", ([
		"兵器坊" : "本店专卖各种长短兵器", 
]) );

	set("vendor_goods", ([
		WEAPON_DIR"sword" : 20,
		WEAPON_DIR"whip": 50,
		WEAPON_DIR"dart": 50,
		WEAPON_DIR"sixhammer":8,
		WEAPON_DIR"dagger":20,
		WEAPON_DIR"staff":4,
		WEAPON_DIR"blade":10,
		__DIR__"obj/armor":3,
]) );

	setup();
        carry_object(WEAPON_DIR"sword")->wield();
}

void init()
{
	object ob;
	::init();
	if( interactive(ob = this_player()) && !is_fighting() )
	{
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() )
		return;

	switch( random(4) )
	{
		case 0:
			command(sprintf("say 这位%s挑一件称手的兵器吧。", RANK_D->query_respect(ob)));
			break;
		case 1:
			command("say 本店全天营业，敬请随时光临。");
			break;
	}
}
