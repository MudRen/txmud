// juewu.c

inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("觉悟", ({ "master juewu", "master", "juewu" }) );

	// master 的必须设置.
	set("class","shaolin");
	create_family("少林寺", 38, "弟子");
	set("inquiry",([
	"leave" : (: call_other, __FILE__, "want_to_leave" :),
	"离开" : (: call_other, __FILE__, "want_to_leave" :),
	"叛师" : (: call_other, __FILE__, "want_to_leave" :),
]));

	set("gender", "男性" );
	set("age", 40);
	set("attitude", "peaceful");

	set("long", "觉悟是少林寺三十八代弟子中的佼佼者，
武功根底非常扎实，同时脾气也很好，
非常有耐心，所以方丈指派他来教授少
林寺入门弟子武功。\n");

	set("combat_exp", 400000);
	set("str", 27);
	set("max_kee",2000);
	set("kee",2000);
	set("max_gin",2000);
	set("gin",2000);
	set("max_sen",2000);
	set("sen",2000);
	set("force", 2500);
	set("max_force", 2500);
	set("atman", 2500);
	set("max_atman", 2500);
	set("mana", 2500);
	set("max_mana", 2500);
	set("force_factor", 50);

	set_skill("dacheng-fofa",100);
	set_skill("chanting",100);
	set_skill("literate",100);
	set_skill("unarmed",100);
	set_skill("dodge",100);
	set_skill("parry",100);
	set_skill("force",80);
	set_skill("magic",80);
	set_skill("spells",50);
	set_skill("sword",100);
	set_skill("iron-cloth",100);
	set_skill("perception",100);
	set_skill("yiqi-force",100);
	set_skill("ganchan",100);
	set_skill("damo-sword",80);
	set_skill("changquan",80);
	set_skill("blade",100);

	map_skill("force","yiqi-force");
	map_skill("dodge","ganchan");
	map_skill("magic","dacheng-fofa");
	map_skill("sword","damo-sword");
	map_skill("unarmed","changquan");

	setup();

	carry_object(WEAPON_DIR"sword")->wield();
	carry_object(__DIR__"obj/seng_pao")->wear();
}

void attempt_apprentice(object ob)
{
	if(ob->query("gender") == "女性")
	{
		command("say 少林寺不收女弟子，这位女施主快点离开吧。");
		return;
	}

	if(!ob->query("is_bonze"))
	{
		command("say 方外之人可以去找觉远师弟学些强身健体之术。");
		return;
	}

	if(ob->query("family/generation") && 
	ob->query("family/generation") <= query("family/generation"))
	{
		command("say 以你现在的武功修为小僧已经没有什么可教你的了。");
		return;
	}

	else
	{
		command("smile");
		command("say 很好，" + RANK_D->query_respect(ob) + "多加努力，他日必定有成。\n");
		command("recruit " + ob->query("id") );
	}
}

int recruit_apprentice(object ob)
{
	::recruit_apprentice(ob);
	ob->set("class", "shaolin");
	return 1;
}

int prevent_learn(object who, string skill)
{
	if(!who->query("is_bonze"))
		return notify_fail("方外之人可以去找觉远师弟学些强身健体之术。\n");
	else if(who->query("bellicosity") > 100)
		return notify_fail(who->name()+"心藏杀机，目露凶光，不合少林武学之基要，");
	else if(time() - who->query("eat_hun_food") < 1440)
	{
		message_vision("$N朝着$n摇摇头说道：罪过！满嘴酒肉之气，又跑出去偷嘴了吧！\n$n满脸惊恐而又假装无辜地说道：“没有！没有！我没有！”\n\n", this_object(), who);
		return 0;
	}
	else
		return ::prevent_learn(who,skill);
}
