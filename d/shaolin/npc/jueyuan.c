// jueyuan.c

inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("觉远", ({ "master jueyuan", "master", "jueyuan" }) );

	// master 的必须设置.
	set("class","shaolin");
	create_family("少林寺", 38, "弟子");
	set("inquiry",([
	"leave" : (: call_other, __FILE__, "want_to_leave" :),
	"离开" : (: call_other, __FILE__, "want_to_leave" :),
	"叛师" : (: call_other, __FILE__, "want_to_leave" :),
]));

	set("gender", "男性" );
	set("age", 33);
	set("attitude", "peaceful");

	set("long", "觉远是受方丈指派专门教授少林寺俗家
弟子一些强身健体之术，虽说武功不是
很高，但深受当地老百姓的喜爱。\n");

	set("combat_exp", 200000);
	set("str", 27);
	set("max_kee",1500);
	set("kee",1500);
	set("max_gin",1500);
	set("gin",1500);
	set("max_sen",1500);
	set("sen",1500);
	set("force", 2000);
	set("max_force", 2000);
	set("atman", 2000);
	set("max_atman", 2000);
	set("mana", 2000);
	set("max_mana", 2000);
	set("force_factor", 20);

	set_skill("dacheng-fofa",100);
	set_skill("chanting",100);
	set_skill("literate",100);
	set_skill("unarmed",80);
	set_skill("dodge",80);
	set_skill("parry",80);
	set_skill("force",80);
	set_skill("magic",80);
	set_skill("spells",50);
	set_skill("stick",100);
	set_skill("iron-cloth",60);
	set_skill("perception",60);
	set_skill("yiqi-force",80);
	set_skill("ganchan",100);

	map_skill("force","yiqi-force");
	map_skill("dodge","ganchan");
	map_skill("magic","dacheng-fofa");

	setup();

	carry_object(WEAPON_DIR"stick")->wield();
	carry_object(__DIR__"obj/seng_pao")->wear();
}


void attempt_apprentice(object ob)
{
	if(ob->query("gender") == "女性")
	{
		command("say 少林寺不收女弟子，这位女施主快点离开吧。");
		return;
	}

	if(ob->query("is_bonze"))
	{
		command("say 我只教授俗家弟子一些强身健体之术，你去找别的大师学习吧。");
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
	ob->set("title","少林寺俗家弟子");
	return 1;
}