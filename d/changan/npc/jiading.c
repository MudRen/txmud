// jiading.c

inherit NPC;

void create()
{
	set_name("家丁", ({ "jia ding"}) );
	set("gender", "男性");
	set("age", 27);

	set("long","这是一位丞相府的家丁，见谁都爱搭不理的。\n");

	set("combat_exp", 300000);
	set("str",40);
	set("con",30);
	set("max_force",2000);
	set("force",2000);
	set("force_factor",10);

	set("max_atman",1000);
	set("atman",1000);
	set("max_mana",1000);
	set("mana",1000);
	set("max_kee",1000);
	set("max_gin",1000);
	set("max_sen",1000);
	set("attitude", "heroism");

	set_skill("unarmed",100);
	set_skill("force",150);
	set_skill("blade", 120);
	set_skill("parry", 100);
	set_skill("dodge", 100);
	setup();

	carry_object(WEAPON_DIR"blade");
	carry_object(ARMOR_DIR"cloth")->wear();
}

void init()
{
	object ob;

	::init();
	if( living(ob = previous_object()) && ob->query_temp("chengxf_killer") )
	{
		message_vision("$N对着$n喊道：“敢到丞相府行凶，真是找死呢！！”\n",
			this_object(),ob);
		kill_ob(ob);
		ob->fight_ob(this_object());
	}
}

int accept_kill(object me)
{
	if(base_name(environment()) == query("startroom"))
		message_vision("$N朝着$n喊道：“跑相府来闹事，不想活啦！！”\n\n",this_object(),me);

	command("wield blade");
	call_out("unwield",2);
	return 1;
}

void unwield()
{
	if(!is_fighting())
		command("unwield blade");
	else
		call_out("unwield",2);
}