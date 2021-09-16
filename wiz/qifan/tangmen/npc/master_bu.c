// master_bu.c

inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("�Ʋ���", ({ "master bu" }) );

	set("class","tangmen");
	create_family("��������", 18, "����");

	set("gender", "����" );
	set("age", 29);
	set("attitude", "peaceful");

	set("long", "�Ʋ���������ʮ�˴������е�ٮٮ�ߡ�
��������������˵ã���˵������
�����������е�ָ�㣬��˵������ᣬ
�ڽ�����Ҳ��������һ�š�\n");

	set("combat_exp", 200000);
	set("str", 27);
	set("max_kee",1500);
	set("kee",1500);
	set("max_gin",1500);
	set("gin",1500);
	set("max_sen",1500);
	set("sen",1500);
	set("force", 2000);
	set("max_force", 2000);
	set("atman", 2000);
	set("max_atman", 2000);
	set("mana", 2000);
	set("max_mana", 2000);
	set("force_factor", 20);

	set_skill("literate",150);
	set_skill("unarmed",100);
	set_skill("dodge",150);
	set_skill("parry",100);
	set_skill("force",100);
	set_skill("magic",100);
	set_skill("spells",100);
	set_skill("sword",100);
	set_skill("throwing",100);
	set_skill("perception",100);

	set_skill("liuhua-sword", 100);
	set_skill("tang-force", 100);
	set_skill("tianchan-steps", 100);
	set_skill("wuying-zhang", 100);
    set_skill("feixue-liantian", 100);

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
	mapping family;

	if( mapp(family = ob->query("family")) )
	{
		if( (family["family_name"] == "��������")
		&& (family["generation"] <= query("family/generation")) )
			command("say û��������ô�������ģ��ѵ�ѧ��ѧ����ѧ�����ˣ�");
		return;
	}

	if(!ob->query_temp("been_recommend_to_tangmen"))
	{
		command("shake");
		command("say �������ŵ��书�����Ҵ���������������Ϊͽ��\n");
		return;
	}

	else
	{
		command("smile");
		command(sprintf("say �ܺã�%s������˻�Ե���Ҿ��������ˡ������Ƽұ���
        �ʹ����ա��ơ������Ժ�ͽ���[��%s]���Ӵ˾����Լ����ˡ�",
			RANK_D->query_respect(ob),
			ob->name() ));
		command("recruit " + ob->query("id") );
	}
}

int recruit_apprentice(object ob)
{
	object mbook;

	::recruit_apprentice(ob);
	ob->delete_temp("been_recommend_to_tangmen");
	ob->delete("decide_enter_tangme_time");
	ob->clear_condition("enter_tangmen");
	ob->clear_condition("tang_du");
	ob->set("class", "tangmen");

	if(objectp(mbook = present("shulin map", ob)))
		destruct(mbook);
	return 1;
}
