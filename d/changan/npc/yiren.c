// yiren.c

inherit F_DEALER;

void create()
{
	set_name("卖艺人", ({ "yiren" }) );
	set("gender", "男性" );
	set("age", 12);
	set("long", "他五短身材，一身短打扮，浑身上下透着精神。\n");
	set("per", 35);
	set("combat_exp", 50000);
	set("attitude", "friendly");

	set_skill("unarmed", 70);
	set_skill("parry", 70);
	set_skill("dodge",90);
	set("sell_all_day",1);

	set("vendor_goods",([
	__DIR__"obj/daliwan":40,
]));


	setup();
	add_money("silver", 2);
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
	if( !ob || environment(ob) != environment() ) return;

	switch (random(3))
	{
		case 0:
			command("say 光说不练假把式！光练不说傻把式！\n");
			break;
		case 1:
			command("say 有钱的捧个钱场，没钱的捧个人场！！！\n");
			break;
		default:
			command("say 都来看看我的祖传秘方配制“回春大力丸”！\n");
	}
}