// huashan masterli.c
// edit by pian

#include <ansi.h>
inherit NPC;
inherit F_MASTER;

string ask_me(object who);
string ask_feng(object who);

void create()
{
	set_name("���ȫ", ({ "master li", "master"}) );

	set("nickname", HIG"ѩͤ�ֶ����"NOR);

	set("class","gaibang");
	set("gender", "����" );
	set("age", 28);
	set("str", 50);
	set("cor", 30);
	set("int", 60);
	set("per", 30);
	set("con", 30);
	set("kar", 50);

	set("max_force", 1000);
	set("force", 1000);
	set("force_factor", 20);

	set("max_gin",800);
	set("max_kee",800);
	set("max_sen",800);

	set("long",@LONG
ؤ��ѩͤ��ֶ���Ĵ����ӣ�����ؤ�������Ͷ��ˡ�
�����˰������ڵ�ؤ���ڹ����䲻���ң�Ҳ���պ����ˡ�
LONG );

	create_family("ؤ��", 8, "�Ĵ�����");
	set("combat_exp", 100000);
	set("score", 3000);

	set("chat_chance", 1);
	set("chat_msg", ({
	"ؤ����ǽ����е�һ���⼸��Ӣ�۱������˲żüá�\n",
	"�������������䡢���˸�����������......\n",
	"�Ǻǣ���ҲҪ�ӽ�����������һ��Ҫ����һֻ�ڴ���\n",
}) );

	set("chat_chance_combat", 60);
	set("chat_msg_combat", ({
		(: exert_function, "recover" :),
}) );

	set_skill("begging",120);
	set_skill("literate",80);
	set_skill("unarmed",120);
	set_skill("parry", 120);
	set_skill("dodge", 120);
	set_skill("stick", 120);
	set_skill("force", 180);
	set_skill("taizu-changquan",120);
	set_skill("taizu-force",180);
	set_skill("gaibang-force",60);
	set_skill("gaibang-steps",120);
	set_skill("taizu-gun", 120);
	
/*	set_skill("huashan-sword", 180);
	set_skill("literate", 160);
	set_skill("zixia-force", 180);
	set_skill("lingyun-steps", 160);
	set_skill("fuyunshou", 160);

	
	map_skill("sword", "huashan-sword");
	map_skill("force", "zixia-force");
*/
	map_skill("unarmed", "taizu-changquan");
	map_skill("stick", "taizu-gun");
	map_skill("dodge","gaibang-steps");
	map_skill("force", "taizu-force");
	set("inquiry", ([
		"ؤ��"      : "ؤ�ؤ�����¸������зֶ氡��",
		"��ʦ"      : "ؤ�����ڹ��͹�������������ؤ����Ҿ����ˡ�",
		"apprentice": "ؤ�����ڹ��͹�������������ؤ����Ҿ����ˡ�",
		"name"	    : "�ұ���ѩͤ��ֶ��Ĵ�����[���ȫ]��",
		"����"      : "ؤ��������ǡ�³�нǡ���Ϻ����",
		"���߹�"    : "��������ʦ�棬�����ʱ���������˼�һ�档",
]) );

	setup();
	//carry_object(__DIR__"/obj/wood_stick")->wield();
	carry_object(ARMOR_DIR"cloth")->wear();
}
   
void attempt_apprentice(object ob)
{
//	if(ob->query("gender") != "����")
//	{ command("say ��ȥ��Сʦ��ȥ�ɡ�"); return; }

//        if(ob->query("class")="gaibang")
//	{
//		command("say ��û�����ɣ�����ô�������������Ӱ���\n");
//		return;
//	}
	if( (ob->query_skill("begging",1) < 80)
		|| (ob->query_skill("taizu-force",1) < 80) )
		{
		command("say ���Ȼ�ȥѧ��[����]��[̫���ķ�]�������������ɡ�\n");
		return;
	}
	
	command("smile");
	command("say �ܺã�" + RANK_D->query_respect(ob) + 
"���Ŭ�������ձض���Ϊһ����ؤ��\n");
	command("recruit " + ob->query("id") );
}


void recruit_apprentice(object ob)
{
	if( ::recruit_apprentice(ob) )
		ob->set("class", "gaibang");
}

string ask_me(object who)
{
	if(!who->is_apprentice_of(this_object()))
		return 0;

	if( (who->query_skill("dodge",1) < 160)
	|| (who->query_skill("taizu-force",1) < 160) )
		return "�����书ѭ�򽥽����ȴ�û�����˵��";

	return "������취���ϾŸ��ڴ���ȥ�������ɡ�";
}

string ask_feng(object who)
{
	if(who->query("class") != "gaibang")
		return 0;

	if(who->query_temp("asked_wyq_about_hqg"))
		return "���Ǻ���˵���ˣ����ú�������������������ʲô��";

	if( (who->query_skill("dodge",1) < 160)
	|| (who->query_skill("zixia-force",1) < 160) )
		return "�������ɵ�ǰ�����ˣ���˵�������Ӳ����ˡ�";

	who->set_temp("asked_wyq_about_hqg",1);
	return "
���߹������ŵ�ʦ���������˼������ĺ�����Ϸ�糾�����޶�
�����������������ˡ�����������Ұ������ʿ�������������
��ȥ�����ǡ�";
}