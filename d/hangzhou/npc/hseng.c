// hseng.c

inherit NPC;
 
void create()
{
        set_name("化缘僧人", ({"seng ren"}));
        set("long", "这是一位化缘的僧人。");
        set("gender","男性");

        set("age",35);
        set("con",20);
        set("str",30);
	set("kar",30);

	set("chat_chance", 10);
	set("chat_msg", ({
		(: random_move :)
	}) );

	set("max_kee",1000);
	set("max_force",1000);
	set("force",1000);
	set("force_factor",10);

	set_skill("unarmed",90);
	set_skill("blade",90);
	set_skill("parry",100);
	set_skill("dodge",90);
	set_skill("force",200);

        set("combat_exp",250000);

        setup();
        carry_object(__DIR__"obj/seng_pao")->wear();
}

int accept_kill(object who)
{
	object ob;

	if(!objectp(present("blade",this_object())))
	{
		message_vision("$N目录凶光，“噌”的一下从腰里摸出一把大砍刀。\n",this_object());
		ob = new(WEAPON_DIR"blade");
		ob->move(this_object());
		ob->wield();
	}
	return 1;
}
