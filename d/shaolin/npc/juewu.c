// juewu.c

inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("����", ({ "master juewu", "master", "juewu" }) );

	// master �ı�������.
	set("class","shaolin");
	create_family("������", 38, "����");
	set("inquiry",([
	"leave" : (: call_other, __FILE__, "want_to_leave" :),
	"�뿪" : (: call_other, __FILE__, "want_to_leave" :),
	"��ʦ" : (: call_other, __FILE__, "want_to_leave" :),
]));

	set("gender", "����" );
	set("age", 40);
	set("attitude", "peaceful");

	set("long", "��������������ʮ�˴������е�ٮٮ�ߣ�
�书���׷ǳ���ʵ��ͬʱƢ��Ҳ�ܺã�
�ǳ������ģ����Է���ָ������������
�������ŵ����书��\n");

	set("combat_exp", 400000);
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
	set("force_factor", 50);

	set_skill("dacheng-fofa",100);
	set_skill("chanting",100);
	set_skill("literate",100);
	set_skill("unarmed",100);
	set_skill("dodge",100);
	set_skill("parry",100);
	set_skill("force",80);
	set_skill("magic",80);
	set_skill("spells",50);
	set_skill("sword",100);
	set_skill("iron-cloth",100);
	set_skill("perception",100);
	set_skill("yiqi-force",100);
	set_skill("ganchan",100);
	set_skill("damo-sword",80);
	set_skill("changquan",80);
	set_skill("blade",100);

	map_skill("force","yiqi-force");
	map_skill("dodge","ganchan");
	map_skill("magic","dacheng-fofa");
	map_skill("sword","damo-sword");
	map_skill("unarmed","changquan");

	setup();

	carry_object(WEAPON_DIR"sword")->wield();
	carry_object(__DIR__"obj/seng_pao")->wear();
}

void attempt_apprentice(object ob)
{
	if(ob->query("gender") == "Ů��")
	{
		command("say �����²���Ů���ӣ���λŮʩ������뿪�ɡ�");
		return;
	}

	if(!ob->query("is_bonze"))
	{
		command("say ����֮�˿���ȥ�Ҿ�Զʦ��ѧЩǿ����֮����");
		return;
	}

	if(ob->query("family/generation") && 
	ob->query("family/generation") <= query("family/generation"))
	{
		command("say �������ڵ��书��ΪСɮ�Ѿ�û��ʲô�ɽ�����ˡ�");
		return;
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
		return notify_fail("����֮�˿���ȥ�Ҿ�Զʦ��ѧЩǿ����֮����\n");
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
