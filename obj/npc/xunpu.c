// xunbu.c

inherit NPC;

void do_move();

void create()
{
	set_name("巡捕", ({ "xun bu"}) );
	set("gender", "男性");
	set("age", 27);

	set("no_exp_gain",1); // 不可得经验的 npc

	set("vendetta_mark", "guanfu");

	set("long","雄赳赳的站着，右手端着一柄钢刀，
警惕的望着过往的人。\n");

	set("combat_exp", 2000000);
	set("str",40);
	set("con",30);
	set("kar",35);
	set("max_force",2000);
	set("force",2000);
	set("force_factor",100);

	set("chat_chance", 15);
	set("chat_msg", ({
		(: do_move :),
	}) );

	set("chat_chance_combat",15);
	set("chat_msg_combat",({
		(: perform_action, "blade.luan" :),
}));

	set("max_atman",2000);
	set("atman",2000);
	set("max_mana",2000);
	set("mana",2000);
	set("max_kee",1500);
	set("max_gin",1500);
	set("max_sen",1500);
	set("attitude", "peaceful");

	set_skill("unarmed",200);
	set_skill("force",150);
	set_skill("blade", 200);
	set_skill("parry", 100);
	set_skill("dodge", 300);
	set_skill("ganchan",180);
	set_skill("lianhuan-blade",180);
	set_skill("feilong-quan",180);

	map_skill("unarmed","feilong-quan");
	map_skill("dodge","ganchan");
	map_skill("parry","lianhuan-blade");
	map_skill("blade","lianhuan-blade");

	setup();
	carry_object(WEAPON_DIR"blade")->wield();
	carry_object(__DIR__"obj/armor")->wear();
}

int accept_fight(object me)
{
	command("say 和我比武？你活得不耐烦啦！！\n");
	message_vision("$N上下打量了一眼$n。\n",this_object(),me);
	return 0;
}

// 巡捕只在户外转.也不应该能出城
void do_move()
{
	mapping exits;
	string *dirs;
	int n,i;
	object ob;
	mixed dest;

	if( !mapp(exits = environment()->query("exits")) )
		return;

	dirs = keys(exits);
	n = sizeof(dirs);
	if(!n) return;

	for(i=0;i<n;i++)
	{
		if(functionp(exits[dirs[i]]))
			dest = evaluate(exits[dirs[i]],this_object());
		else
			dest = exits[dirs[i]];

		if(objectp(dest))
			ob = dest;
		else
		{
			if(!objectp(ob = find_object(dest)) && !objectp(ob = load_object(dest)) )
			{
				dirs[i] = 0;
				continue;
			}
		}
		if(!ob->query("outdoors")
		|| (environment()->query("outdoors") 
		&& ob->query("outdoors") != environment()->query("outdoors")))
			dirs[i] = 0;
	}

	dirs -= ({ 0 });
	if(!sizeof(dirs))
		return;

	command("go " + dirs[random(sizeof(dirs))]);
}