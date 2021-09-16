// dutu.c

inherit NPC;

void create()
{
	set_name("赌徒", ({ "du tu" }) );
	set("gender", "男性" );
	set("age", 38);

	set("long", "这是一位刚输得精光的赌徒。\n");

	set("combat_exp", 5000);
	set("per",20);
	set("str", 27);
	set("force", 200);
	set("max_force", 200);
	set("force_factor", 2);
	set_skill("unarmed",50);

	setup();

	carry_object(ARMOR_DIR"cloth")->wear();
}

int accept_fight(object me)
{
	command("say 老子刚输的一个字儿也没有了，哪有心情比武！！\n");
	return 0;
}
 
void init()
{
	object ob;

	::init();
	if (interactive(ob = this_player()) && !is_fighting())
	{
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
}
 
void greeting(object ob)
{
	if(!ob || environment(ob) != environment())
		return;

	command(sprintf("look %s",ob->query("id")));
	command(sprintf("say 这位%s能不能借几两银子用用？！",RANK_D->query_respect(ob)));
}

int accept_object(object me, object ob)
{
	if(!ob->query("money_id"))
		return 0;

	if(ob->value() < 100000)
	{
		command("say 多谢这位" + RANK_D->query_respect(me) + "，等我赢了一定加倍还你！");
		call_out("do_destruct",1,ob);
		return 1;
	}

	call_out("do_point",2,me,ob);
	return 1;
}

void do_destruct(object ob)
{
	if(objectp(ob))
		destruct(ob);
}

private void do_point(object me,object ob)
{
	if(!me || environment(me) != environment() || !living(me))
		return;

	message_vision("$N扑通一声跪在$n面前说道：您真是我的重生父母！再造爹娘！\n可是这钱我这辈子也还不起您。\n\n",
		this_object(),me);

	command(sprintf("tell %s 不过我知道一个秘密告诉您就当报恩吧。长安北面的山里有一
                   个“排云寨”，就在枫晓亭向东那一带，有一条向北的路一直
                   向上走就到了，那里是个杀人不眨眼的土匪盘踞的地方，非常
                   危险！排云寨的后山有一位世外高人隐居在那里，那人年轻的
                   时候是一位赌国高手。",me->query("id")));

	me->set_temp("pass_changan_dutu",1);
	if(ob)
		call_out("do_destruct",1,ob);
}
