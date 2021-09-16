// caifeng_boss.c

inherit NPC;

void create()
{
	set_name("李大嫂", ({ "boss li", "boss","li" }) );
	set("gender", "女性" );
	set("title","裁缝铺老板");
        set("age", 35);
	set("per",20);
        set("long","这是一位朴实的山里大嫂。\n");
        set("combat_exp", 10000);

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

	say( "李大嫂微笑着。\n");

}
