// qiangdao.c
// by 发现号(Find) 10/98.

inherit NPC;

int silver_number;

void create()
{
	set_name("蒙面强盗", ({"qiang dao" }) );
	set("gender", "男性" );
	set("long","一个头蒙黑布的大汉，手里拎着一把明晃晃的大片刀。\n");
        set("attitude", "heroism");
	set("class","lanlu_qiangdao");

	set("age",20+random(8));
	set("per",14);
	set("con",30);
	set("int",30);
	set("str", 50);
	set("max_force",2000);
	set("force",2000);
	set("force_factor",150);
	set("max_mana",1500);
	set("mana",1500);
	set("max_atman",1500);
	set("atman",1500);
	set("kee",2500);
	set("gin",2500);
	set("sen",2500);
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
}

int accept_object(object who,object ob)
{
	if(who != query("person"))
		return 0;

	if(!ob->query("money_id"))
		return notify_fail(name()+"说道：“ 什么破东西，快拿钱来！”\n");

	if(ob->value()< (silver_number*100))
		return notify_fail(name()+"说道：“ 这么几个钱打发要饭的呢！快拿"+
			chinese_number(silver_number)+"两银子来！”\n");

	return notify_fail(name()+"点点头说道：“ 把钱给我们老大就行了，这小子到老实。”\n");
}

int accept_fight(object who)
{
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