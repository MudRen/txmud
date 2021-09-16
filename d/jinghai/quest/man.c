// man.c

inherit NPC;

object master;

int is_fanren() {return 1;}
int is_quest_object() { return 1;}

object query_master() { return master; }
int set_master(object ob)
{
	if(!objectp(ob))
		return 0;

	master = ob;

	set_leader(ob);
	remove_all_killer();
	return 1;
}

void rand_move()
{
	if(!objectp(master))
		::random_move();
}

void create()
{
	set_name("����", ({"none"}));

	set("long", "����һλ�����񶾵������ˡ�\n");
	set("gender","����");
	set("title","�����ӷ�");

	set("no_exp_gain",1);
	set("chat_chance", 6);
	set("chat_msg", ({
		(: rand_move :),
}));

	set("attitude","peaceful");
        set("age",30+random(10));
        set("con",30);
        set("str",25);
        set("per",15);
        set("kar",30);
	set("max_kee",1000);
	set("max_gin",1000);
	set("max_sen",1000);
	set("max_force",1200);
	set("force",1200);
	set("force_factor",20);

	set_skill("dodge",100);
	set_skill("parry",100);
	set_skill("unarmed",150);
	set_skill("force",150);
	set_skill("blade",100);
	set_skill("jinghai-force",150);
	set_skill("longjiao-blade",70);
	set_skill("xian-steps",70);

	map_skill("dodge","xian-steps");
	map_skill("parry","longjiao-blade");
	map_skill("blade","longjiao-blade");
	map_skill("force","jinghai-force");

	set("combat_exp",350000);

        setup();
        carry_object(ARMOR_DIR"cloth")->wear();
	carry_object(WEAPON_DIR"blade")->wield();
}

void die()
{
	remove_all_killer();
	return;
}

int follow_me(object ob, string dir)
{
	if(!master || !ob)
		return 0;

	if( (ob == master) && !query_leader())
		set_leader(ob);

	return ::follow_me(ob, dir);
}

int heal_up()
{
	int n,time = time();

	if(!n = query("on_time"))
		set("on_time",time);

	else
	{
		if( (time-n > 900) && !is_fighting() && !objectp(master))
		{
			call_out("do_leave",1);
			return 1;
		}
	}

	return ::heal_up() + 1;
}

void do_leave()
{
	if(!living(this_object()))
		return;

	if(environment())
		tell_room(environment(),sprintf("%s�Ҵ�ææ�����ˡ�\n",name()));
	destruct(this_object());
}
