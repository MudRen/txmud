// teacher.c

inherit NPC;

string heal_me(object me);

string learn_ok();
void deleteall(object me);

void create()
{
	set_name("赛华佗", ({ "sai hua tuo" }) );
	set("title", "神医");
	set("gender", "男性" );
	set("age", 58);
	set("str",30);
	set("int", 30);
	set("combat_exp",1);
	set("long",
		"赛华佗是一个年过古稀的老人，但走起路来仍非常稳健，干起活来仍然非常利索\n"
		"他虽然开着这家药铺，但却对此心不在焉。\n");
	set("inquiry", ([
		"治伤": (: heal_me :),
		"疗伤": (: heal_me :),
		"开药": (: heal_me :),
		"用毒": (: learn_ok :),
	]) );

	set_skill("literate", 70);
	set_skill("dodge", 60);
	set_skill("unarmed", 60);
	setup();
	add_money("coin", 80);
}

void init()
{
	::init();
}

string heal_me(object me)
{
	int ratio;

	ratio = (int)me->query("eff_kee") * 100 / (int)me->query("max_kee");
	if( ratio >= 100 )
		return "这位" + RANK_D->query_respect(me) + "，您看起来气色很好啊，不像有受伤的样子。";
	if( ratio >= 95 )
		return "哦....我看看....只是些皮肉小伤，您买包金创药回去敷敷就没事了。";
	
}

string learn_ok()
{
	object me;
	me = this_player();
	    command("say "+RANK_D->query_respect(me)+"找错人了吧!\n");
		command("say 我是治病的，怎么会那种东西。\n");
	if( me->query_skill("dujing") >= 5 ) {
		me->set_temp("marks/赛华佗ok",1);
		return "看你如此诚心，我就告诉你一点皮毛。不过吗...... 那就看你怎么做了。";
	} else {
	return "你一定是道听途说，不要什么都信。";
	}
}

int recognize_apprentice(object ob)
{
	int num;
	if( !ob->query_temp("marks/赛华佗") ){
		say("赛华佗说道：咦？我可什么都不会啊....\n");
		return 0;
	}
	num = ob->query_temp("marks/赛华佗") -1;
	ob->set_temp("marks/赛华佗",ob->query_temp("marks/赛华佗")-1);
	return 1;
}

int accept_object(object who, object ob)
{
	if( who->query_temp("marks/赛华佗ok") ) {
		if( !who->query_temp("marks/赛华佗") ) {
			if( ob->value() >= 1000){
				say("赛华佗说道：很好，现在你可以来问我有关毒经(dujing)\n"
					"         的任何问题。\n");
				who->set_temp("marks/赛华佗", (int)ob->value()/1000);
				return 1;
			} else {
				say("赛华佗说道：你的诚意不够，这钱还是拿回去吧。\n");
				return 0;
			}
		} else {
			say("赛华佗点了点头，说道：哦，象你这麽有心的学生还真是不多见，好好努力\n"
				"                      将来必定前途无量，谢了。\n");
			say("对了，可千万别说是我教过你哦。\n");
			return 1;
		}
	} else {
		say("老朽何德何能，能叫您破费，真是不好意思。\n");
		return 0;
	}
}


int accept_learn(object me, string skill)
{
	if (me->query_temp("marks/赛华佗ok")) 
		return 1;
	else
		return 0;
}
int accept_fight(object me)
{
        command("say 我一个糟老头子，你还是放过我吧！\n");
        return 0;
}

void accept_kill(object me)
{
	object *fellow;
	int i;
	fellow = all_inventory(environment(this_object()));
	for (i=0;i<sizeof(fellow);i++)
	{
		if (fellow[i]->query("id")=="purple guard")
		{
			fellow[i]->kill_ob(me);
			fellow[i]->set_temp("guarding","south");
		}
	}
}

