// qianjin.c

inherit NPC;

int have = 0;

void create()
{
	set_name("林秋纹", ({"lin qiuwen", "qiuwen"}));
	set("title","丞相千金");

	set("long", "这位就是相府的千金。");
	set("gender","女性");
	set("attitude","peaceful");

        set("age",15);
	set("per",35);
	set("max_kee",1500);

	set_skill("unarmed",20);

        set("combat_exp",6000+random(6000));

        setup();
        carry_object(__DIR__"obj/buqun")->wear();
}

int accept_kill(object me)
{
	object ob,girl;

	message_vision("$N喊道：“哎呀！！来人哪！救命呀！！”\n\n",this_object());
	if(objectp(girl = present("servant girl",environment())) && living(girl))
		tell_room(environment(),"小丫鬟尖声喊道：“快来人哪！有人刺杀小姐啦！！”\n");

	me->set_temp("chengxf_killer",1);

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

	if(have)
		return;

	message_vision("$N喊道：“快来人呀！有人偷东西啦！！”\n\n",this_object());

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