// jueyuan.c

inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("��Զ", ({ "master jueyuan", "master", "jueyuan" }) );

	// master �ı�������.
	set("class","shaolin");
	create_family("������", 38, "����");
	set("inquiry",([
	"leave" : (: call_other, __FILE__, "want_to_leave" :),
	"�뿪" : (: call_other, __FILE__, "want_to_leave" :),
	"��ʦ" : (: call_other, __FILE__, "want_to_leave" :),
]));

	set("gender", "����" );
	set("age", 33);
	set("attitude", "peaceful");

	set("long", "��Զ���ܷ���ָ��ר�Ž����������׼�
����һЩǿ����֮������˵�书����
�ܸߣ������ܵ����ϰ��յ�ϲ����\n");

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

	set_skill("dacheng-fofa",100);
	set_skill("chanting",100);
	set_skill("literate",100);
	set_skill("unarmed",80);
	set_skill("dodge",80);
	set_skill("parry",80);
	set_skill("force",80);
	set_skill("magic",80);
	set_skill("spells",50);
	set_skill("stick",100);
	set_skill("iron-cloth",60);
	set_skill("perception",60);
	set_skill("yiqi-force",80);
	set_skill("ganchan",100);

	map_skill("force","yiqi-force");
	map_skill("dodge","ganchan");
	map_skill("magic","dacheng-fofa");

	setup();

	carry_object(WEAPON_DIR"stick")->wield();
	carry_object(__DIR__"obj/seng_pao")->wear();
}


void attempt_apprentice(object ob)
{
	if(ob->query("gender") == "Ů��")
	{
		command("say �����²���Ů���ӣ���λŮʩ������뿪�ɡ�");
		return;
	}

	if(ob->query("is_bonze"))
	{
		command("say ��ֻ�����׼ҵ���һЩǿ����֮������ȥ�ұ�Ĵ�ʦѧϰ�ɡ�");
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
	ob->set("title","�������׼ҵ���");
	return 1;
}