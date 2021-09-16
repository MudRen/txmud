// qiangdao_t.c
// by 发现号(Find) 10/98.

inherit NPC;

int silver_number;

void create()
{
	set_name("强盗头", ({"qiangdao leader", "leader"}) );
	set("gender", "男性" );
	set("long","一个头蒙黑布的大汉，手里拎着一把明晃晃的大片刀。\n");
        set("attitude", "heroism");
	set("class","lanlu_qiangdao");
	set("get_money",0);

	set("age",30+random(8));
	set("per",14);
	set("con",30);
	set("int",30);
	set("str", 50);
	set("max_force",3000);
	set("force",3000);
	set("force_factor",200);
	set("max_mana",2000);
	set("mana",2000);
	set("max_atman",2000);
	set("atman",2000);
	set("kee",4000);
	set("gin",4000);
	set("sen",4000);

	set("chat_chance_combat",15);
	set("chat_msg_combat",({
		(: perform_action, "blade.luan" :),
}));

	set_skill("unarmed", 50);
	set_skill("dodge", 50);
	set_skill("parry", 50);
	set_skill("blade", 50);
	set_skill("force", 50);
	set_skill("ganchan",50);
	set_skill("lianhuan-blade",50);
	set_skill("feilong-quan",50);

	map_skill("unarmed","feilong-quan");
	map_skill("dodge","ganchan");
	map_skill("parry","lianhuan-blade");
	map_skill("blade","lianhuan-blade");

	set("combat_exp", 10000);

	setup();

	carry_object(ARMOR_DIR"cloth")->wear();
	carry_object(__DIR__"obj/glaive")->wield();
}

void init()
{
	add_action("do_kill","kill");
}

void set_attribute(object me)
{
	int i,n,skill_level = 50;
	string *skill_name;
	int exp = me->query("combat_exp");

	silver_number = (me->query("age")/10)*10;
	set("person",me);

	if(exp <= 20000)
		return;

	if(arrayp(skill_name = me->query_skills_name()))
	{
		for(i=0;i<sizeof(skill_name);i++)
		{
		if( (string)SKILL_D(skill_name[i])->type() != "martial" )
			continue;
		if( (n = me->query_skill(skill_name[i], 1)) > skill_level )
			skill_level = n;
		}

		skill_level += skill_level/10 - random(2*skill_level/10);

		set_skill("unarmed", skill_level);
		set_skill("dodge", skill_level);
		set_skill("parry", skill_level);
		set_skill("blade", skill_level);
		set_skill("force", skill_level);
		set_skill("ganchan",skill_level);
		set_skill("lianhuan-blade",skill_level);
		set_skill("feilong-quan",skill_level);
	}
	exp = exp /10 * 9;
	if(exp > 2000000)
		exp = 2000000;
	set("combat_exp",exp );

	set("combat_exp",exp );
}

int accept_object(object who,object ob)
{
	object *obs,target;
	int i;

	target = query("person");

	if(!target || who != target)
	{
		if(!ob->query("money_id") || ob->query("money_id") == "coin")
			call_out("do_drop",1,ob->query("id"));
		return 1;
	}

	if(!ob->query("money_id"))
		return notify_fail(name()+"说道：“ 这是什么破东西！快拿钱来！”\n");

	if(ob->value()< (silver_number*100))
		return notify_fail(name()+"说道：“ 这么几个钱打发要饭的呢！快拿"+
			chinese_number(silver_number)+"两银子来！”\n");

	// 足额付款：
	if(find_call_out("do_ask"))
		remove_call_out("do_ask");
	if(find_call_out("kill_person"))
		remove_call_out("kill_person");
	if(find_call_out("do_lasting"))
		remove_call_out("do_lasting");

	if(is_fighting(who))
	{
		this_object()->remove_killer(who);
		who->remove_enemy(this_object());
		command("say 早这样多好，你可以走了，下回遇到老子给钱痛快点！\n");
		//GUARD_CMD->main(this_object(),"cancel");
		this_object()->set_leader();
	}

	else
	{
		command("nod");
		command("say 以后走夜路记着多带点钱孝敬老子。你可以走了。\n");
		//GUARD_CMD->main(this_object(),"cancel");
		this_object()->set_leader();
	}

	if( obs = query("tonghuo") )
	{
		for( i=0;i<sizeof(obs);i++)
		{
			obs[i]->remove_killer(who);
			who->remove_enemy(obs[i]);
			//GUARD_CMD->main(obs[i],"cancel");
		}
	}

	call_out("do_leave",1);

	return 1;
}

void do_drop(string id)
{
	object ob = present(id,this_object());

	if(!ob) return;

	tell_room(environment(),name()+"拿起"+ob->name()+"看了看。\n");
	command("drop "+id);
}

int accept_fight(object who)
{
	if(query("get_money"))
	{
		command("say 好小子！试试吧。\n");
		return 1;
	}

	if(who != query("person"))
	{
		command("say 别捣乱！老子正在做买卖呢！\n");
		return 0;

	}

	command("say 谁有功夫比武，赶快拿钱来！\n");
	return 0;
}

int do_kill(string arg)
{
	object ob;

	if(!arg)
		return 0;

	if(!ob = present(arg,environment()))
		return 0;

	if(ob == this_object())
		return 0;

	if(ob->query("class") && ob->query("class") == "lanlu_qiangdao")
	{
		command("say 简直不想活了！\n");
		this_object()->kill_ob(this_player());
		this_player()->kill_ob(this_object());
		return 0;
	}
	return 0;
}

void ask_money()
{
	remove_call_out("begin_ask");
	call_out("do_ask",4,1);
}

void do_ask(int i)
{
	object who = query("person");

	if(!who || environment(who) != environment())
	{
		call_out("do_leave",1);
		return;
	}

	else
		switch (i)
		{
			case 1:
				if(environment(who) == environment())
					message_vision("$N对$n说道：赶快拿钱来，留你一条小命！\n",
						this_object(),who);
				call_out("do_ask",12,++i);
				return;
			case 2:
				if(environment(who) == environment())
					message_vision("$N对$n喊道：要钱还是要命，痛快点  ！\n",
						this_object(),who);
				call_out("do_ask",14,++i);
				return;
			case 3:
				call_out("do_lasting",8);
				if(this_object()->is_fight(who))
					return;
				if(environment(who) != environment())
					return;
				message_vision("$N对$n喊道：看你真是要钱不要命！\n",
					this_object(),who);
				remove_call_out("kill_person");
				call_out("kill_person",8);
				return;
		}
}

void kill_person()
{
	object who = query("person");
	object *obs;
	int i;
        if(!objectp(who))
                return;

	if(this_object()->is_fighting(who))
		return;
	if((environment(who) != environment()) || environment()->query(SAFE_ENV))
	{
		call_out("do_lasting",1);
		return;
	}

	this_object()->kill_ob(who);
	who->fight_ob(this_object());

	obs = query("tonghuo");
	if(!arrayp(obs))
		return;
	obs -= ({0});

	if(sizeof(obs))
		for(i=0;i<sizeof(obs);i++)
		{
			obs[i]->kill_ob(who);
			who->fight_ob(obs[i]);
		}

	return;
}

void do_remove()
{
	object *obs,env;

	if(!living(this_object()))
		revive(0);

	set_leader(0);

	obs = query("tonghuo");
	if(!obs)
		obs = ({});
	obs -= ({ 0 });

	if(env = environment())
		tell_object(env,name()+"抬头看看天,喊道：“不好！天亮了！"+
			((sizeof(obs))?"伙计们 扯呼！":"")+"”\n说罢"+
			((sizeof(obs))?"带头":"扭头")+"就跑，几个转弯人就不见了。\n");
	if(sizeof(obs))
		for(int i=0;i<sizeof(obs);i++)
		{
			if(obs[i] && environment(obs[i]))
			{
				if(env && env == environment(obs[i]))
					tell_object(env,obs[i]->name()+"跟着"+
						name()+"一起跑了。\n");
				else
				{
					if(obs[i]->is_fighting())
						tell_object(environment(obs[i]),
						obs[i]->name()+"说声：“不打了！”，"+
						"扭头就跑，几个转弯人就不见了。\n");
					else
						tell_object(environment(obs[i]),
						obs[i]->name()+"悄悄溜了。\n");
				}
			}
			destruct(obs[i]);
		}
	destruct(this_object());
}

void char_was_died(object ob,object corpse)
{
	object target,env;

	target = query("person");

	if(ob && ob == target)
	{
		if(env = environment())
			tell_room(env,name()+"冷笑一声说道：“不识好歹的东西，舍命不舍财。”\n",({ob}));
		call_out("do_leave",2);
	}
}

void do_leave()
{
	object *obs,env;
	int i;

	remove_call_out("do_leave");

	if(!living(this_object()) || is_fighting())
	{
		call_out("do_leave",3);
		return;
	}

	command("get all from corpse");

	obs = query("tonghuo");
	if(!obs)
		obs = ({});

	obs -= ({0});
	env = environment();

	if(env)
	{
		if(sizeof(obs))
			tell_object(env,name()+"大声招呼道：“伙计们！回去啦！”\n");
		tell_object(env,name()+"晃着膀子走了。\n");
	}

	for(i=0;i<sizeof(obs);i++)
	{
		if(environment(obs[i]))
			tell_object(environment(obs[i]),sprintf("%s%s%s走了。\n",
				obs[i]->name(),
				(obs[i]->is_fighting())?"突然高喊：“不打了！”，说罢":"",
				(environment(obs[i])==env)?"跟着"+name():"晃着膀子"));
		destruct(obs[i]);
	}

	destruct(this_object());
	return;
}

void die()
{
	object *obs;

	obs = query("tonghuo");
	if(!obs)
		obs = ({});
	obs -= ({0});

	for(int i=0;i<sizeof(obs);i++)
	{
		if(living(obs[i])
		&& environment(obs[i])
		&& environment(obs[i]) == environment())
		{
			tell_object(environment(),obs[i]->name()+"看到"+name()+"都打不过，吓得扭头就跑。\n");
			destruct(obs[i]);
		}
	}
	::die();
}

void do_lasting()
{
	object who = query("person");
	string *mote = ({"$N朝着$n一阵冷笑。\n",
"$N掂着手中的片刀看着$n。\n",
"$N对着说道：“识相的赶紧掏钱！”\n"
});

	remove_call_out("do_lasting");

	if(!who || environment(who) != environment())
	{
		call_out("do_leave",2);
		return;
	}

	if(is_fighting())
	{
		call_out("do_lasting",5);
		return;
	}

	if(!environment()->query(SAFE_ENV))
	{
		this_object()->kill_ob(who);
		who->fight_ob(this_object());
	}
	else
	{
		message_vision(mote[random(sizeof(mote))],this_object(),who);
		call_out("do_lasting",5);
	}
}
