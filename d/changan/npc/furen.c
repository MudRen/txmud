// furen.c

inherit NPC;

int have = 0;
 
void create()
{
	set_name("丞相夫人", ({"fu ren"}));
	set("long", @LONG
这位就是当朝宰相林文畏的夫人。他出身于江南
的名门旺族娇小姐，自嫁给林丞相，相夫教子，
贤名卓著。只见她仪态万方。
LONG
);
	set("gender","女性");
        set("age",35);
        set("per",35);
	set("attitude","peaceful");

	set_skill("unarmed",50);

        set("combat_exp",2000+random(2000));

        setup();
	carry_object(__DIR__"obj/hongduan_skirt")->wear();
	carry_object(__DIR__"obj/zhuhua")->wear();
}

int accept_fight(object me)
{
	if(base_name(environment()) == query("startroom"))
		message_vision("$N看看$n说道：“你是哪来的？怎么敢跑到丞相府撒野？！”\n",
		this_object(),me);
	return 0;
}

int accept_kill(object me)
{
	object ob;

	message_vision("$N喊道：“要造反啦！来人！！把他轰出去！！”\n\n",this_object());

	if(have)
		return 1;

	for(int i=0;i<2;i++)
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

	message_vision("$N喊道：“胆敢到这来偷东西！来人！！把他轰出去！！”\n\n",this_object());

	if(have)
		return;

	for(int i=0;i<2;i++)
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