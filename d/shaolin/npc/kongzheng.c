// kongzheng.c

inherit NPC;

string ask_tuijian(object who);

void create()
{
	set_name("����", ({ "kong zheng", "seng" }) );

	set("class","shaolin");
	create_family("������", 37, "����");

	set("attitude", "friendly");
	set("gender", "����" );
	set("age", 48);
	set("long", "����һλ��ĸߴ��ɮ�ˣ��Ӹ߸�¡��
��̫��Ѩ�Ͽ��ɼ���һλ�书���֡�\n");

	set("inquiry", ([
		"�Ƽ���": (: ask_tuijian :),
		"�Ƽ�": (: ask_tuijian :),
]) );

	set("combat_exp", 400000);
	set("str", 40);
	set("kar",30);
	set("max_kee",1000);
	set("max_gin",1000);
	set("max_sen",1000);
	set("force", 2000);
	set("max_force", 2000);
	set("atman", 2000);
	set("max_atman", 2000);
	set("mana", 2000);
	set("max_mana", 2000);
	set("force_factor", 20);

	set_skill("unarmed",80);
	set_skill("dodge",90);
	set_skill("parry",90);
	set_skill("force",100);
	set_skill("iron-cloth",100);
	set_skill("perception",100);
	set_skill("yiqi-force",100);
	set_skill("ganchan",80);
	set_skill("changquan",80);

	map_skill("force","yiqi-force");
	map_skill("dodge","ganchan");
	map_skill("unarmed","changquan");

	setup();

	carry_object(__DIR__"obj/seng_pao")->wear();
}

string ask_tuijian(object who)
{
	int bf_who,bf_this;
	mapping fam;

	fam = who->query("family");

	if(!fam || fam["family_name"] != "������")
		return 0;

	if(!who->query("is_bonze"))
		return "�׼ҵ��Ӻ;�Զ�ú�ѧЩǿ����֮���Ϳ����ˡ�\n";

	if(is_fighting())
		return "��һ����ɡ�\n";

	bf_who = fam["generation"];
	bf_this = query("family/generation");

	if( bf_who <= (bf_this+1) )
		return "���Ѿ��Ƽ���������ô�������ң����ȥ�ú������ɡ�\n";

	if(who->query_skill("dacheng-fofa",1) < 90)
		return "�����½������ļ��ޣ���ķ���Ϊ̫���ˡ�\n";

	if(who->query_temp("have_tuijianxin"))
		return "�Ƽ��Ų��Ǹոո����ˣ����ȥ�ú������ɡ�\n";

	if( ((query("kee")*100)/query("max_kee") < 90) || (query("force") < 500))
		return "�������е��ۣ�������Ϣһ�ᡣ��һ�������д�һ�����ա�\n";

	who->set_temp("pass_check",1);
	return "�����д�(fight)һ���书��������ĸ�����Ρ�\n";
}

int accept_fight(object ob)
{
	if(!ob->query_temp("pass_check"))
		return 0;

	if(is_fighting())
	{
		command( "say ��һ����ɡ�\n" );
		return 0;
	}

        if( ((query("kee")*100)/query("max_kee") < 90)||(query("force") < 500))
        {
                command("say �������е����ˣ��Ȼ��ٱȡ�");
                return 0;
        }

	ob->delete_temp("pass_check");
	remove_call_out("check_state");
	call_out("check_state",1,ob);
	return 1;
}

int accept_kill(object ob)
{
	remove_call_out("check_state");
	return 1;
}

void check_state(object ob)
{
	int mm_kee;
	object xin;

	remove_call_out("check_state");

	if(!ob || environment(ob) != environment())
		return;

	if(is_fighting())
	{
		if(member_array(ob,query_enemy()) != -1)
			call_out("check_state",2,ob);
		return;
	}

	mm_kee = query("max_kee");

	// success.
	if( (query("kee") * 100 / mm_kee) <= 50 )
	{
		command("say �ã��ã�����Ȼ�ǿ���֮�ţ�");
		xin = new(__DIR__"obj/tuijianxin");
		xin->set("from_shaolin_kongzheng",1);
		xin->set("tuijian",ob->query("id"));
		xin->set("long",sprintf("������ʮ�Ŵ�����%s����ѧ����������\n���ޣ�����С�ɣ��ɿ���͡�\n",
			ob->name()));
		message_vision("$N����$nһ���Ƽ��š�\n", this_object(), ob);
		xin->move(ob);
		return;
	}

	// fail.
	command(sprintf("say ����%s��Ҫ����������������ɾ͡�",ob->name()));
	return;
}
