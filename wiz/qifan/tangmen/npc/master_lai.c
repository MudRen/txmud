// master_lai.c

inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("�Ƽ���", ({ "master lai" }) );

	set("class","tangmen");
	create_family("��������", 17, "����");

	set("gender", "����" );
	set("age", 43);
	set("attitude", "peaceful");

	set("long", "�Ƽ���Ҳ��������������һ��������
���ˣ������ó����Ƕ��Ͱ������Ը�
�ֲ�ҩ���о�������΢�������ù���
��̫Ϥ��ָ�㡣\n");

	set("combat_exp", 200000);
	set("str", 37);
	set("max_kee",5500);
	set("kee",5500);
	set("max_gin",5500);
	set("gin",5500);
	set("max_sen",5500);
	set("sen",5500);
	set("force", 10000);
	set("max_force", 10000);
	set("atman", 10000);
	set("max_atman", 10000);
	set("mana", 10000);
	set("max_mana", 10000);
	set("force_factor", 200);

	set_skill("literate",220);
	set_skill("unarmed",150);
	set_skill("dodge",150);
	set_skill("parry",150);
	set_skill("force",150);
	set_skill("magic",150);
	set_skill("spells",150);
	set_skill("sword",150);
	set_skill("throwing",150);
	set_skill("perception",150);

	set_skill("medicine", 200);

	set_skill("tang-du", 150);
	set_skill("liuhua-sword", 150);
    set_skill("feixue-liantian", 550);
	set_skill("tang-force", 150);
	set_skill("tianchan-steps", 150);
	set_skill("wuying-zhang", 150);

	//map_skill("medicine","tang-du");
	map_skill("unarmed","wuying-zhang");
	map_skill("throwing","wuying-zhang");
	map_skill("force","tang-force");
	map_skill("dodge","tianchan-steps");
	map_skill("sword","liuhua-sword");

	setup();

	carry_object(WEAPON_DIR"sword")->wield();
	carry_object(ARMOR_DIR"cloth")->wear();
}

void attempt_apprentice(object ob)
{
	mapping family,ski;
	object mb;

	if( !mapp(family = ob->query("family")) || ( family["family_name"] != "��������") )
	{
		command("shake");
		command("say �������ŵ��书�����Ҵ���������������Ϊͽ��\n");
		return;
	}

	if(family["generation"] <= query("family/generation"))
	{
		command("say û��������ô�������ģ��ѵ�ѧ��ѧ����ѧ�����ˣ�");
		return;
	}

	if(!mb = find_object(__DIR__"master_bu"))
		mb = load_object(__DIR__"master_bu");
	if(!mb || !sizeof(ski = mb->query_skills()))
	{
		tell_object(ob, "���Ű�ʦ�������⣬��֪ͨ����Ա����\n");
		return;
	}

	foreach(string sk, int lv in ski)
	{
		if(lv > ob->query_skill(sk, 1))
		{
			tell_object(ob, sprintf("%sҡͷ˵���������书���������ȴ����%s̫���ˡ�\n",
				name(), to_chinese(sk)));
			return;
		}
	}

	command("smile");
	command(sprintf("say �ܺã�%s�Ժ�Ҫ���Ŭ����",
		RANK_D->query_respect(ob) ));
	command("recruit " + ob->query("id") );
}

int recruit_apprentice(object ob)
{
	::recruit_apprentice(ob);
	ob->set("class", "tangmen");
	return 1;
}
