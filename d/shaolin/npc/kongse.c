// kongse.c

inherit NPC;
inherit F_MASTER;

string ask_jing(object me);

void create()
{
	set_name("空色", ({ "master kongse", "master", "kongse" }) );

	// master 的必须设置.
	set("class","shaolin");
	create_family("少林寺", 37, "弟子");
	set("inquiry",([
	"leave" : (: call_other, __FILE__, "want_to_leave" :),
	"离开" : (: call_other, __FILE__, "want_to_leave" :),
	"叛师" : (: call_other, __FILE__, "want_to_leave" :),
	"经书" : (: ask_jing :),
	"jing" : (: ask_jing :),
]));

	set("gender", "男性" );
	set("age", 52);
	set("attitude", "peaceful");

	set("long", "这是一位满脸和善的僧人，但从眼中的
精光和高高隆起的太阳穴上可见也是一
位武功好手。\n");

	set("combat_exp", 1800000);
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
	set("force_factor", 150);

	set("chat_chance_combat",25);
	set("chat_msg_combat",({
		(: perform_action, "blade.cibei" :),
}));

	set_skill("dacheng-fofa",200);
	set_skill("chanting",200);
	set_skill("literate",200);
	set_skill("unarmed",200);
	set_skill("dodge",200);
	set_skill("parry",200);
	set_skill("force",200);
	set_skill("magic",200);
	set_skill("spells",150);
	set_skill("stick",200);
	set_skill("iron-cloth",220);
	set_skill("perception",220);
	set_skill("yiqi-force",200);
	set_skill("ganchan",200);
	set_skill("changquan",200);
	set_skill("luohan-quan",200);
	set_skill("weituo-gun",200);
	set_skill("jingang",200);
	set_skill("blade",200);
	set_skill("cibei-blade",200);

	map_skill("force","yiqi-force");
	map_skill("dodge","ganchan");
	map_skill("magic","dacheng-fofa");
	map_skill("unarmed","luohan-quan");
	map_skill("stick","weituo-gun");
	map_skill("iron-cloth","jingang");
	map_skill("blade","cibei-blade");
	map_skill("parry","cibei-blade");
	map_skill("stick","weituo-gun");

	setup();

	carry_object(__DIR__"obj/jiedao")->wield();
	carry_object(__DIR__"obj/seng_pao")->wear();
}

void attempt_apprentice(object ob)
{
	int bf_ob,bf_master;

	if(ob->query("gender") == "女性")
	{
		command("say 少林寺不收女弟子，这位女施主快点离开吧。");
		return;
	}

	if(!ob->query("is_bonze"))
	{
		command("say 方外之人可以去找觉远师侄学些强身健体之术。");
		return;
	}

	if(!ob->query("family"))
	{
		command("say 本寺武功讲究循序渐进、厚积薄发，你先去找觉悟禅师吧。");
		return;
	}

	bf_ob = ob->query("family/generation");
	bf_master = query("family/generation");

	if( bf_ob && bf_ob <= bf_master )
	{
		command("say 以你现在的武功修为老纳已经没有什么可教你的了。");
		return;
	}

	if( bf_ob > (bf_master+1) )
	{
		object xin;

		xin = present("tuijian xin",ob);

		if(!xin || xin->query("tuijian") != ob->query("id"))
		{
			command("say 我只收由空正师弟推荐来的弟子，你去找他吧。");
			return;
		}
		command("say 好，好，能得到空正师弟的推荐很不容易，得英才而教之乃一大快事。");
		command("say 望你今后勤学苦练，百尺竿头，更进一步。");
		destruct(xin);
		command("recruit " + ob->query("id") );
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
		return notify_fail("方外之人可以去找觉远师侄学些强身健体之术。\n");
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

string ask_jing(object me)
{
	object jing;

	jing = new(__DIR__"obj/jingshu");
	jing->move(this_object());
	command("give jing shu to "+me->query("id"));
	return "此经尽载佛家精要，望天下人都能领悟，善哉。\n";
}