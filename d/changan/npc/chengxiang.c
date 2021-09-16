// chengxiang.c

inherit NPC;

int have;

void create()
{
	set_name("林文畏", ({"lin wenwei", "wenwei", "lin"}));
	set("title","当朝宰相");

	set("long", @LONG
他就是当朝的丞相，据说当今皇上当太子的时候一
次在关外遇难，当时还是县令的林丞相舍身相救，
太子登基以后对他一力提拔，林丞相自己也是兢兢
业业，因此深的皇上的宠爱。
LONG
);

	set("gender","男性");
	set("vendetta_mark", "guanfu");
	set("attitude","peaceful");

        set("age",55);
	set("str",45);
	set("kar",45);

	set("max_kee",2500);
	set("max_gin",2500);
	set("max_sen",2500);

	set_skill("unarmed",160);
	set_skill("dodge",160);
	set_skill("parry",160);

        set("combat_exp",1000000);

        setup();
        carry_object(__DIR__"obj/mangpao")->wear();
}

void init()
{
	object ob;

	::init();
	if( living(ob = previous_object()) && ob->query_temp("chengxf_killer") )
	{
		message_vision("$N对着$n喊道：“敢到丞相府行凶，真是找死呢！！”\n",
			this_object(),ob);
		kill_ob(ob);
		ob->fight_ob(this_object());
	}
}

int accept_kill(object me)
{
	object ob;

	message_vision(sprintf("$N喊道：“这是要造反了吗！来人！！把%s给我宰了！！”\n\n",
		gender_pronoun(me->query("gender"))),this_object());

	me->set_temp("chengxf_killer",1);

	if(have)
		return 1;

	for(int i=0;i<3;i++)
	{
		ob = new(__DIR__"cxf_huyuan");
		ob->move(environment());
		message_vision("$N从外面跑了进来喊道：“小子！活够了吗？！”\n\n",ob);
		ob->set_leader(me);
		ob->kill_ob(me);
		me->fight_ob(ob);
	}

	have = 1;

	return 1;
}


void detect_stealing(object me)
{
	object ob;

	if(!me)
		return;

	message_vision(sprintf("$N喊道：“好个小毛贼敢到这来偷东西！来人！！把%s给我宰了！！”\n\n",
		gender_pronoun(me->query("gender"))),this_object());

	if(have)
		return;

	for(int i=0;i<3;i++)
	{
		ob = new(__DIR__"cxf_huyuan");
		ob->move(environment());
		message_vision("$N从外面跑了进来喊道：“小子！活够了吗？！”\n\n",ob);
		ob->set_leader(me);
		ob->kill_ob(me);
		me->fight_ob(ob);
	}

	have = 1;

	return;
}