// master_zhen.c

inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("唐震中", ({ "master zhen" }) );

	set("class","tangmen");
	create_family("蜀中唐门", 16, "堡主");

	set("gender", "男性" );
	set("age", 55);
	set("attitude", "peaceful");

	set("long", "唐震中就是蜀中唐家的十六代堡主，
是前代堡主的独生爱子，天资聪颖，
从小就勤学好武，不到三十岁便名
震武林，数十年的不懈努力，武功
已盖过唐家前人。\n");

	set("combat_exp", 800000);
	set("str", 57);
	set("max_kee",9000);
	set("kee",9000);
	set("max_gin",9000);
	set("gin",9000);
	set("max_sen",9000);
	set("sen",9000);
	set("force", 20000);
	set("max_force", 20000);
	set("atman", 20000);
	set("max_atman", 20000);
	set("mana", 20000);
	set("max_mana", 20000);
	set("force_factor", 400);

	set_skill("literate",320);
	set_skill("unarmed",280);
	set_skill("dodge",320);
	set_skill("parry",280);
	set_skill("force",280);
	set_skill("magic",260);
	set_skill("spells",260);
	set_skill("sword",300);
	set_skill("throwing",290);
	set_skill("perception",290);

	set_skill("liuhua-sword", 300);
	set_skill("tang-force", 280);
	set_skill("tang-du", 250);
	set_skill("tianchan-steps", 300);
	set_skill("wuying-zhang", 290);
	set_skill("medicine", 200);

	//map_skill("medicine","tang-du");
	map_skill("unarmed","wuying-zhang");
	map_skill("throwing","wuying-zhang");
	map_skill("force","tang-force");
	map_skill("dodge","tianchan-steps");
	map_skill("sword","liuhua-sword");

	setup();

	carry_object(WEAPON_DIR"sword")->wield();
	carry_object(ARMOR_DIR"cloth")->wear();
}


void attempt_apprentice(object ob)
{
	mapping family,lski, yski;
	object ml, my;

	if( !mapp(family = ob->query("family")) || ( family["family_name"] != "蜀中唐门") )
	{
		command("shake");
		command("say 蜀中唐门的武功向来家传，从来不收外人为徒。\n");
		return;
	}

	if(family["generation"] <= query("family/generation"))
	{
		command("say 没见过你这么不长进的，难道学着学着又学回来了！");
		return;
	}

	if(!my = find_object(__DIR__"master_yuan"))
		my = load_object(__DIR__"master_yuan");
	if(!my || !sizeof(yski = my->query_skills()))
	{
		tell_object(ob, "唐门拜师 master yuan 出现问题，请通知管理员处理。\n");
		return;
	}

	if(!ml = find_object(__DIR__"master_lai"))
		ml = load_object(__DIR__"master_lai");
	if(!ml || !sizeof(lski = ml->query_skills()))
	{
		tell_object(ob, "唐门拜师 master lai 出现问题，请通知管理员处理。\n");
		return;
	}

	foreach(string sk, int lv in yski)
	{
		if(lv > ob->query_skill(sk, 1))
		{
			tell_object(ob, sprintf("%s摇头说道：我派武功讲究稳扎稳打，你的%s太差了。\n",
				name(), to_chinese(sk)));
			return;
		}
	}

	foreach(string sk, int lv in lski)
	{
		if(lv > ob->query_skill(sk, 1))
		{
			tell_object(ob, sprintf("%s摇头说道：我派武功讲究稳扎稳打，你的%s太差了。\n",
				name(), to_chinese(sk)));
			return;
		}
	}

	command("smile");
	command("say 很好，" + RANK_D->query_respect(ob) + "多加努力，他日必定有成。\n");
	command("recruit " + ob->query("id") );
}

int recruit_apprentice(object ob)
{
	::recruit_apprentice(ob);
	ob->set("class", "tangmen");
	return 1;
}
