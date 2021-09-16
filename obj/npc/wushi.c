// wushi.c

int my_move();

inherit NPC;

int open_heart_beat() { return 1; }

void create()
{
	set_name("����", ({ "bukuai"}) );
	set("gender", "����");
	set("age", 27);

	set("no_exp_gain",1); // ���ɵþ���� npc

	set("long",     "�������վ�ţ����ֶ���һ�˴󵶣�
��������Ź������ˡ�\n");

	set("chat_chance_combat",30);
	set("chat_msg_combat",({
		(: perform_action, "blade.luan" :),
		(: perform_action, "unarmed.tan" :),
}));

	set("combat_exp", 5000000);
	set("str",60);
	set("con",60);
	set("kar",50);
	set("max_force",30000);
	set("force",30000);
	set("force_factor",200);

	set("max_atman",20000);
	set("atman",20000);
	set("max_mana",20000);
	set("mana",20000);
	set("max_kee",5000);
	set("max_gin",5000);
	set("max_sen",5000);
	set("attitude", "heroism");

	set_skill("unarmed",250);
	set_skill("force",250);
	set_skill("blade", 250);
	set_skill("parry", 250);
	set_skill("dodge", 300);
	set_skill("ganchan",300);
	set_skill("lianhuan-blade",250);
	set_skill("feilong-quan",250);

	map_skill("unarmed","feilong-quan");
	map_skill("dodge","ganchan");
	map_skill("parry","lianhuan-blade");
	map_skill("blade","lianhuan-blade");

	setup();
	carry_object(WEAPON_DIR"blade")->wield();
	carry_object(__DIR__"obj/armor")->wear();
}

void set_sks(object me)
{
	return;
/*
	mapping skills;
	int i,n,skill_level = 150;
	string *skill_name;

	int exp = me->query("combat_exp");

	if(exp <= 600000)
		return;

	if(mapp(skills = me->query_skills()))
	{
		skill_name = keys(skills);
		for(i=0;i<sizeof(skill_name);i++)
		{
		if( (string)SKILL_D(skill_name[i])->type() != "martial" )
			continue;
		if( (n = me->query_skill(skill_name[i], 1)) > skill_level )
			skill_level = n;
		}

		skill_level += skill_level/10 - random(2*skill_level/10);

		set_skill("unarmed", skill_level);
		set_skill("bloodystrike",skill_level);
		set_skill("dodge", skill_level);
		set_skill("parry", skill_level);
		set_skill("blade", skill_level);
		set_skill("force", skill_level);
		set_skill("longxiang",skill_level);
		set_skill("linbo-steps",skill_level);
		set_skill("moriblade", skill_level);
	}

	set("combat_exp",exp + random(exp/10) );
*/
}

int heal_up()
{
	object ob = this_object()->query("kill");

	if( !ob || ob->is_ghost() || !ob->query_condition("pker_kill") )
	{
		if( !is_fighting() )
		{
			call_out("leave", 1);
			return 1;
		}
        }
        return ::heal_up() + 1;
}

void leave()
{
	if(environment())
	message("vision",name()+"���ˡ�\n",environment(),this_object());
	destruct(this_object());
}

void die()
{
	object *obj , ob = this_object()->query("kill");

	if(ob && (ob == query_temp("last_damage_from")))
	{
	if(obj = ob->query("guanfu_weijiao"))
		{
		obj -= ({this_object()});
		ob->set("guanfu_weijiao",obj);
		}
	}
	::die();
}
