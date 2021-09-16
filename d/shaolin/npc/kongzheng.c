// kongzheng.c

inherit NPC;

string ask_tuijian(object who);

void create()
{
	set_name("空正", ({ "kong zheng", "seng" }) );

	set("class","shaolin");
	create_family("少林寺", 37, "弟子");

	set("attitude", "friendly");
	set("gender", "男性" );
	set("age", 48);
	set("long", "这是一位身材高大的僧人，从高高隆起
的太阳穴上看可见是一位武功好手。\n");

	set("inquiry", ([
		"推荐信": (: ask_tuijian :),
		"推荐": (: ask_tuijian :),
]) );

	set("combat_exp", 400000);
	set("str", 40);
	set("kar",30);
	set("max_kee",1000);
	set("max_gin",1000);
	set("max_sen",1000);
	set("force", 2000);
	set("max_force", 2000);
	set("atman", 2000);
	set("max_atman", 2000);
	set("mana", 2000);
	set("max_mana", 2000);
	set("force_factor", 20);

	set_skill("unarmed",80);
	set_skill("dodge",90);
	set_skill("parry",90);
	set_skill("force",100);
	set_skill("iron-cloth",100);
	set_skill("perception",100);
	set_skill("yiqi-force",100);
	set_skill("ganchan",80);
	set_skill("changquan",80);

	map_skill("force","yiqi-force");
	map_skill("dodge","ganchan");
	map_skill("unarmed","changquan");

	setup();

	carry_object(__DIR__"obj/seng_pao")->wear();
}

string ask_tuijian(object who)
{
	int bf_who,bf_this;
	mapping fam;

	fam = who->query("family");

	if(!fam || fam["family_name"] != "少林寺")
		return 0;

	if(!who->query("is_bonze"))
		return "俗家弟子和觉远好好学些强身健体之术就可以了。\n";

	if(is_fighting())
		return "等一会儿吧。\n";

	bf_who = fam["generation"];
	bf_this = query("family/generation");

	if( bf_who <= (bf_this+1) )
		return "我已经推荐过你了怎么还来找我，快回去好好练功吧。\n";

	if(who->query_skill("dacheng-fofa",1) < 90)
		return "少林寺讲究身心兼修，你的佛法修为太差了。\n";

	if(who->query_temp("have_tuijianxin"))
		return "推荐信不是刚刚给你了，快回去好好练功吧。\n";

	if( ((query("kee")*100)/query("max_kee") < 90) || (query("force") < 500))
		return "我现在有点累，让我休息一会。等一下咱们切磋一下武艺。\n";

	who->set_temp("pass_check",1);
	return "咱们切磋(fight)一下武功，看看你的根基如何。\n";
}

int accept_fight(object ob)
{
	if(!ob->query_temp("pass_check"))
		return 0;

	if(is_fighting())
	{
		command( "say 等一会儿吧。\n" );
		return 0;
	}

        if( ((query("kee")*100)/query("max_kee") < 90)||(query("force") < 500))
        {
                command("say 我现在有点累了，等会再比。");
                return 0;
        }

	ob->delete_temp("pass_check");
	remove_call_out("check_state");
	call_out("check_state",1,ob);
	return 1;
}

int accept_kill(object ob)
{
	remove_call_out("check_state");
	return 1;
}

void check_state(object ob)
{
	int mm_kee;
	object xin;

	remove_call_out("check_state");

	if(!ob || environment(ob) != environment())
		return;

	if(is_fighting())
	{
		if(member_array(ob,query_enemy()) != -1)
			call_out("check_state",2,ob);
		return;
	}

	mm_kee = query("max_kee");

	// success.
	if( (query("kee") * 100 / mm_kee) <= 50 )
	{
		command("say 好，好！！果然是可造之才！");
		xin = new(__DIR__"obj/tuijianxin");
		xin->set("from_shaolin_kongzheng",1);
		xin->set("tuijian",ob->query("id"));
		xin->set("long",sprintf("本寺三十九代弟子%s，勤学苦练，身心\n兼修，已有小成，可堪造就。\n",
			ob->name()));
		message_vision("$N交给$n一封推荐信。\n", this_object(), ob);
		xin->move(ob);
		return;
	}

	// fail.
	command(sprintf("say 看来%s还要多加修炼才能有所成就。",ob->name()));
	return;
}
