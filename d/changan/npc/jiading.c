// jiading.c

inherit NPC;

void create()
{
	set_name("�Ҷ�", ({ "jia ding"}) );
	set("gender", "����");
	set("age", 27);

	set("long","����һλة�ฮ�ļҶ�����˭�������ġ�\n");

	set("combat_exp", 300000);
	set("str",40);
	set("con",30);
	set("max_force",2000);
	set("force",2000);
	set("force_factor",10);

	set("max_atman",1000);
	set("atman",1000);
	set("max_mana",1000);
	set("mana",1000);
	set("max_kee",1000);
	set("max_gin",1000);
	set("max_sen",1000);
	set("attitude", "heroism");

	set_skill("unarmed",100);
	set_skill("force",150);
	set_skill("blade", 120);
	set_skill("parry", 100);
	set_skill("dodge", 100);
	setup();

	carry_object(WEAPON_DIR"blade");
	carry_object(ARMOR_DIR"cloth")->wear();
}

void init()
{
	object ob;

	::init();
	if( living(ob = previous_object()) && ob->query_temp("chengxf_killer") )
	{
		message_vision("$N����$n���������ҵ�ة�ฮ���ף����������أ�����\n",
			this_object(),ob);
		kill_ob(ob);
		ob->fight_ob(this_object());
	}
}

int accept_kill(object me)
{
	if(base_name(environment()) == query("startroom"))
		message_vision("$N����$n�����������ฮ�����£��������������\n\n",this_object(),me);

	command("wield blade");
	call_out("unwield",2);
	return 1;
}

void unwield()
{
	if(!is_fighting())
		command("unwield blade");
	else
		call_out("unwield",2);
}