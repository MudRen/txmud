// master_yuan.c

inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("唐继远", ({ "master yuan" }) );

	set("class","tangmen");
	create_family("蜀中唐门", 17, "弟子");

	set("gender", "男性" );
	set("age", 43);
	set("attitude", "peaceful");

	set("long", "唐继远是是堡主的亲传大弟子，
武功方面已得唐门武功精髓，虽
说火候还不够，在江湖上的名声
已经是响当当了。\n");

	set("combat_exp", 200000);
	set("str", 37);
	set("max_kee",5500);
	set("kee",5500);
	set("max_gin",5500);
	set("gin",5500);
	set("max_sen",5500);
	set("sen",5500);
	set("force", 10000);
	set("max_force", 10000);
	set("atman", 10000);
	set("max_atman", 10000);
	set("mana", 10000);
	set("max_mana", 10000);
	set("force_factor", 200);

	set_skill("literate",220);
	set_skill("unarmed",220);
	set_skill("dodge",200);
	set_skill("parry",200);
	set_skill("force",200);
	set_skill("magic",200);
	set_skill("spells",200);
	set_skill("sword",200);
	set_skill("throwing",220);
	set_skill("perception",220);

	set_skill("liuhua-sword", 200);
	set_skill("tang-force", 200);
	set_skill("tianchan-steps", 200);
	set_skill("wuying-zhang", 220);

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
	mapping family,ski;
	object mb;

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

	if(!mb = find_object(__DIR__"master_bu"))
		mb = load_object(__DIR__"master_bu");
	if(!mb || !sizeof(ski = mb->query_skills()))
	{
		tell_object(ob, "唐门拜师出现问题，请通知管理员处理。\n");
		return;
	}

	foreach(string sk, int lv in ski)
	{
		if(lv > ob->query_skill(sk, 1))
		{
			tell_object(ob, sprintf("%s摇头说道：我派武功讲究稳扎稳打，你的%s太差了。\n",
				name(), to_chinese(sk)));
			return;
		}
	}

	command("smile");
	command(sprintf("say 很好，%s以后要多加努力。",
		RANK_D->query_respect(ob) ));
	command("recruit " + ob->query("id") );
}

int recruit_apprentice(object ob)
{
	::recruit_apprentice(ob);
	ob->set("class", "tangmen");
	return 1;
}
