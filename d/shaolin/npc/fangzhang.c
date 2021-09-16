// fangzhang.c

inherit NPC;
inherit F_MASTER;

string ask_me(object me);
string ask_yijin(object me);

void create()
{
	set_name("晦智", ({ "abbot huizhi", "huizhi", "abbot" }) );

	// master 的必须设置.
	set("class","shaolin");
	create_family("少林寺", 36, "方丈");
	set("inquiry",([
	"leave" : (: call_other, __FILE__, "want_to_leave" :),
	"离开" : (: call_other, __FILE__, "want_to_leave" :),
	"叛师" : (: call_other, __FILE__, "want_to_leave" :),
	"铜人阵" : (: ask_me :),
	"易筋经" : (: ask_yijin :),
]));

	set("gender", "男性" );
	set("age", 83);
	set("attitude", "peaceful");

	set("long", "这是一位慈眉善目的老和尚，他就是少
林寺现任方丈晦智大师。\n");

	set("combat_exp", 6000000);
	set("str", 57);
	set("kar", 45);
	set("cor", 80);
	set("max_kee",3500);
	set("kee",3500);
	set("max_gin",3500);
	set("gin",3500);
	set("max_sen",3500);
	set("sen",3500);
	set("force", 5000);
	set("max_force", 5000);
	set("atman", 5000);
	set("max_atman", 5000);
	set("mana", 5000);
	set("max_mana", 5000);
	set("force_factor", 600);

	set_skill("dacheng-fofa",300);
	set_skill("chanting",500);
	set_skill("literate",300);
	set_skill("unarmed",280);
	set_skill("dodge",280);
	set_skill("parry",280);
	set_skill("force",280);
	set_skill("magic",300);
	set_skill("spells",250);
	set_skill("stick",280);
	set_skill("sword",260);
	set_skill("iron-cloth",300);
	set_skill("perception",300);
	set_skill("yiqi-force",280);
	set_skill("ganchan",280);
	set_skill("changquan",200);
	set_skill("cibei-blade",280);
	set_skill("damo-sword",260);
	set_skill("jingang",300);
	set_skill("blade",280);
	set_skill("luohan-quan",280);
	set_skill("weituo-gun",280);

	map_skill("force","yiqi-force");
	map_skill("dodge","ganchan");
	map_skill("magic","dacheng-fofa");
	map_skill("iron-cloth","jingang");
	map_skill("unarmed","luohan-quan");

	setup();

	carry_object(__DIR__"obj/jiasha")->wear();
}

string ask_yijin(object me)
{
	string *ski;
	mapping all;
	int n;

	if( (me->query("class") != "shaolin")
	|| !me->is_apprentice_of(this_object()) )
		return 0;

	if(me->query("family/can_study_yijin"))
		return "不是已经准许你参修《易筋经》了，你去找晦痴大师吧。\n";

	all = query_skills();
	ski = keys(all) - ({"chanting","literate","magic","spells","perception"});

	n = sizeof(ski);

	for(int i=0;i<n;i++)
		if( me->query_skill(ski[i],1) < (all[ski[i]] - 10) )
			return sprintf("你的『%s』修为不足，还无法参悟《易筋经》。\n",to_chinese(ski[i]));

	me->set("family/can_study_yijin",1);

	return "《易筋经》虽然短小，但内容博大精深，涵盖了古往今来的武学精要，
          如能参悟透彻，可使武功更上一层楼，但参悟此经不但需
          要绝高的悟性耐心，还需要绝大缘法，你为我少林后辈之
          中的佼佼者，望你能参透此经，将少林武学发扬光大。你
          现在去找晦痴大师吧。";
}

void attempt_apprentice(object ob)
{
	if(ob->query("gender") == "女性")
	{
		command("say 少林寺不收女弟子，这位女施主快点离开吧。");
		return;
	}

	if(!ob->query("family/passed_tongren"))
	{
		command("say 老纳年事已高，收徒授法已经是心有余而力不足了。");
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

string ask_me(object me)
{
	int t;

	if(me->query("class") != "shaolin")
		return 0;

	if(me->query_temp("fangzhang_pass"))
		return "不是让你去找晦法大师了吗。\n";

	if(me->query("family/passed_tongren"))
		return "你已过『铜人阵』，好好去修炼武学、佛法吧。\n";

	if(me->query_temp("pass_tongren") == 3)
	{
		me->delete_temp("pass_tongren");
		me->delete("family/try_tongren");
		me->set("family/passed_tongren",1);
		call_out("do_reward",1,me);
		return "好，好，居然闯过『铜人阵』，前途不可限量，理应奖励。\n";
	}

	if( (t = me->query("family/try_tongren")) && (time() - t) < 86400 )
		return "刚试过闯『铜人阵』，休息休息再说吧";

	if(me->query("family/generation") > 38)
		return "你先好好去修炼武学、佛法吧，不可贪功猛进。\n";

	me->set_temp("fangzhang_pass",1);
	return "你既然有此心愿就去试试吧，你去找晦法大师。\n";
}

protected void do_reward(object me)
{
	me->add("combat_exp",5000);
	me->add("potential",3000);
	me->add_shimen_gongji(3000);

	tell_object(me,sprintf("\n你得到了：\n\t%d 点实战经验\n\t%d 点潜能\n\t%d 点师们功绩\n\n",
		5000,3000,3000));

	CHANNEL_D->do_channel(this_object(), "menpai",sprintf("%s %s(%s) 试闯『铜人阵』通过！！\n",
		me->query("title"),me->name(),capitalize(me->query("id"))));
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
