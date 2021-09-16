// qiangdao_t.c
// by ���ֺ�(Find) 10/98.

inherit NPC;

int silver_number;

void create()
{
	set_name("ǿ��ͷ", ({"qiangdao leader", "leader"}) );
	set("gender", "����" );
	set("long","һ��ͷ�ɺڲ��Ĵ󺺣���������һ�����λεĴ�Ƭ����\n");
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
		return notify_fail(name()+"˵������ ����ʲô�ƶ���������Ǯ������\n");

	if(ob->value()< (silver_number*100))
		return notify_fail(name()+"˵������ ��ô����Ǯ��Ҫ�����أ�����"+
			chinese_number(silver_number)+"������������\n");

	// ���
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
		command("say ��������ã���������ˣ��»��������Ӹ�Ǯʹ��㣡\n");
		//GUARD_CMD->main(this_object(),"cancel");
		this_object()->set_leader();
	}

	else
	{
		command("nod");
		command("say �Ժ���ҹ·���Ŷ����ǮТ�����ӡ���������ˡ�\n");
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

	tell_room(environment(),name()+"����"+ob->name()+"���˿���\n");
	command("drop "+id);
}

int accept_fight(object who)
{
	if(query("get_money"))
	{
		command("say ��С�ӣ����԰ɡ�\n");
		return 1;
	}

	if(who != query("person"))
	{
		command("say ���ң����������������أ�\n");
		return 0;

	}

	command("say ˭�й�����䣬�Ͽ���Ǯ����\n");
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
		command("say ��ֱ������ˣ�\n");
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
					message_vision("$N��$n˵�����Ͽ���Ǯ��������һ��С����\n",
						this_object(),who);
				call_out("do_ask",12,++i);
				return;
			case 2:
				if(environment(who) == environment())
					message_vision("$N��$n������ҪǮ����Ҫ����ʹ���  ��\n",
						this_object(),who);
				call_out("do_ask",14,++i);
				return;
			case 3:
				call_out("do_lasting",8);
				if(this_object()->is_fight(who))
					return;
				if(environment(who) != environment())
					return;
				message_vision("$N��$n��������������ҪǮ��Ҫ����\n",
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
		tell_object(env,name()+"̧ͷ������,�����������ã������ˣ�"+
			((sizeof(obs))?"����� ������":"")+"��\n˵��"+
			((sizeof(obs))?"��ͷ":"Ťͷ")+"���ܣ�����ת���˾Ͳ����ˡ�\n");
	if(sizeof(obs))
		for(int i=0;i<sizeof(obs);i++)
		{
			if(obs[i] && environment(obs[i]))
			{
				if(env && env == environment(obs[i]))
					tell_object(env,obs[i]->name()+"����"+
						name()+"һ�����ˡ�\n");
				else
				{
					if(obs[i]->is_fighting())
						tell_object(environment(obs[i]),
						obs[i]->name()+"˵�����������ˣ�����"+
						"Ťͷ���ܣ�����ת���˾Ͳ����ˡ�\n");
					else
						tell_object(environment(obs[i]),
						obs[i]->name()+"�������ˡ�\n");
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
			tell_room(env,name()+"��Цһ��˵��������ʶ�ô��Ķ�������������ơ���\n",({ob}));
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
			tell_object(env,name()+"�����к�����������ǣ���ȥ������\n");
		tell_object(env,name()+"���Ű������ˡ�\n");
	}

	for(i=0;i<sizeof(obs);i++)
	{
		if(environment(obs[i]))
			tell_object(environment(obs[i]),sprintf("%s%s%s���ˡ�\n",
				obs[i]->name(),
				(obs[i]->is_fighting())?"ͻȻ�ߺ����������ˣ�����˵��":"",
				(environment(obs[i])==env)?"����"+name():"���Ű���"));
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
			tell_object(environment(),obs[i]->name()+"����"+name()+"���򲻹����ŵ�Ťͷ���ܡ�\n");
			destruct(obs[i]);
		}
	}
	::die();
}

void do_lasting()
{
	object who = query("person");
	string *mote = ({"$N����$nһ����Ц��\n",
"$N�������е�Ƭ������$n��\n",
"$N����˵������ʶ��ĸϽ���Ǯ����\n"
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
