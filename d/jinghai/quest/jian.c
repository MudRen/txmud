// jianxi.c

inherit NPC;

int is_quest_object() { return 1;}

void create()
{
	set_name("��ϸ", ({"jian xi"}));

	set("long", "���˹�������������֮ɫ��\n");
	set("gender","����");

	set("no_exp_gain",1);

	set("chat_chance", 6);
	set("chat_msg", ({
		(: random_move :),
}));

	set("env/wimpy",10);
	set("attitude","peaceful");
        set("age",36);
        set("con",30);
        set("str",25);
        set("per",15);
        set("kar",25);
	set("max_kee",1200);
	set("max_gin",1200);
	set("max_sen",1200);
	set("max_force",1200);
	set("force",1200);
	set("force_factor",20);

	set_skill("dodge",150);
	set_skill("parry",150);
	set_skill("unarmed",150);
	set_skill("force",150);
	set_skill("blade",150);

	set("combat_exp",20000);

        setup();
        carry_object(ARMOR_DIR"cloth")->wear();
	carry_object(WEAPON_DIR"blade")->wield();
}

int heal_up()
{
	int n,time = time();

	if(!n = query("on_time"))
		set("on_time",time);

	else
	{
		if( (time-n > 900) && !is_fighting())
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
