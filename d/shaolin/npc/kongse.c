// kongse.c

inherit NPC;
inherit F_MASTER;

string ask_jing(object me);

void create()
{
	set_name("��ɫ", ({ "master kongse", "master", "kongse" }) );

	// master �ı�������.
	set("class","shaolin");
	create_family("������", 37, "����");
	set("inquiry",([
	"leave" : (: call_other, __FILE__, "want_to_leave" :),
	"�뿪" : (: call_other, __FILE__, "want_to_leave" :),
	"��ʦ" : (: call_other, __FILE__, "want_to_leave" :),
	"����" : (: ask_jing :),
	"jing" : (: ask_jing :),
]));

	set("gender", "����" );
	set("age", 52);
	set("attitude", "peaceful");

	set("long", "����һλ�������Ƶ�ɮ�ˣ��������е�
����͸߸�¡���̫��Ѩ�Ͽɼ�Ҳ��һ
λ�书���֡�\n");

	set("combat_exp", 1800000);
	set("str", 27);
	set("max_kee",2000);
	set("kee",2000);
	set("max_gin",2000);
	set("gin",2000);
	set("max_sen",2000);
	set("sen",2000);
	set("force", 2500);
	set("max_force", 2500);
	set("atman", 2500);
	set("max_atman", 2500);
	set("mana", 2500);
	set("max_mana", 2500);
	set("force_factor", 150);

	set("chat_chance_combat",25);
	set("chat_msg_combat",({
		(: perform_action, "blade.cibei" :),
}));

	set_skill("dacheng-fofa",200);
	set_skill("chanting",200);
	set_skill("literate",200);
	set_skill("unarmed",200);
	set_skill("dodge",200);
	set_skill("parry",200);
	set_skill("force",200);
	set_skill("magic",200);
	set_skill("spells",150);
	set_skill("stick",200);
	set_skill("iron-cloth",220);
	set_skill("perception",220);
	set_skill("yiqi-force",200);
	set_skill("ganchan",200);
	set_skill("changquan",200);
	set_skill("luohan-quan",200);
	set_skill("weituo-gun",200);
	set_skill("jingang",200);
	set_skill("blade",200);
	set_skill("cibei-blade",200);

	map_skill("force","yiqi-force");
	map_skill("dodge","ganchan");
	map_skill("magic","dacheng-fofa");
	map_skill("unarmed","luohan-quan");
	map_skill("stick","weituo-gun");
	map_skill("iron-cloth","jingang");
	map_skill("blade","cibei-blade");
	map_skill("parry","cibei-blade");
	map_skill("stick","weituo-gun");

	setup();

	carry_object(__DIR__"obj/jiedao")->wield();
	carry_object(__DIR__"obj/seng_pao")->wear();
}

void attempt_apprentice(object ob)
{
	int bf_ob,bf_master;

	if(ob->query("gender") == "Ů��")
	{
		command("say �����²���Ů���ӣ���λŮʩ������뿪�ɡ�");
		return;
	}

	if(!ob->query("is_bonze"))
	{
		command("say ����֮�˿���ȥ�Ҿ�ԶʦֶѧЩǿ����֮����");
		return;
	}

	if(!ob->query("family"))
	{
		command("say �����书����ѭ�򽥽����������������ȥ�Ҿ�����ʦ�ɡ�");
		return;
	}

	bf_ob = ob->query("family/generation");
	bf_master = query("family/generation");

	if( bf_ob && bf_ob <= bf_master )
	{
		command("say �������ڵ��书��Ϊ�����Ѿ�û��ʲô�ɽ�����ˡ�");
		return;
	}

	if( bf_ob > (bf_master+1) )
	{
		object xin;

		xin = present("tuijian xin",ob);

		if(!xin || xin->query("tuijian") != ob->query("id"))
		{
			command("say ��ֻ���ɿ���ʦ���Ƽ����ĵ��ӣ���ȥ�����ɡ�");
			return;
		}
		command("say �ã��ã��ܵõ�����ʦ�ܵ��Ƽ��ܲ����ף���Ӣ�Ŷ���֮��һ����¡�");
		command("say ��������ѧ�������ٳ߸�ͷ������һ����");
		destruct(xin);
		command("recruit " + ob->query("id") );
	}

	else
	{
		command("smile");
		command("say �ܺã�" + RANK_D->query_respect(ob) + "���Ŭ�������ձض��гɡ�\n");
		command("recruit " + ob->query("id") );
	}
}

int recruit_apprentice(object ob)
{
	::recruit_apprentice(ob);
	ob->set("class", "shaolin");
	return 1;
}

int prevent_learn(object who, string skill)
{
	if(!who->query("is_bonze"))
		return notify_fail("����֮�˿���ȥ�Ҿ�ԶʦֶѧЩǿ����֮����\n");
	else if(who->query("bellicosity") > 100)
		return notify_fail(who->name()+"�Ĳ�ɱ����Ŀ¶�׹⣬����������ѧ֮��Ҫ��");
	else if(time() - who->query("eat_hun_food") < 1440)
	{
		message_vision("$N����$nҡҡͷ˵����������������֮�������ܳ�ȥ͵���˰ɣ�\n$n�������ֶ��ּ�װ�޹���˵������û�У�û�У���û�У���\n\n", this_object(), who);
		return 0;
	}
	else
		return ::prevent_learn(who,skill);
}

string ask_jing(object me)
{
	object jing;

	jing = new(__DIR__"obj/jingshu");
	jing->move(this_object());
	command("give jing shu to "+me->query("id"));
	return "�˾����ط�Ҿ�Ҫ���������˶����������ա�\n";
}