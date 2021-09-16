// huashan mastermei.c
// edit by pian

#include <ansi.h>
inherit NPC;
inherit F_MASTER;

string ask_me(object who);
string ask_feng(object who);

void create()
{
	set_name("÷��Ȩ", ({ "master mei", "master"}) );

	//set("nickname", HIG""NOR);

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
ؤ��ѩͤ��ֶ�Ķ������ӣ�����ؤ�������Ͷ��ˡ�
LONG );

	create_family("ؤ��", 10, "��������");
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

	set_skill("begging",80);
	set_skill("literate",40);
	set_skill("unarmed",80);
	set_skill("parry", 80);
	set_skill("dodge", 80);
	set_skill("stick", 80);
	set_skill("force", 80);
	set_skill("taizu-changquan",60);
	set_skill("taizu-force",40);
	set_skill("gaibang-steps",60);
	
/*	set_skill("huashan-sword", 180);
	set_skill("literate", 160);
	set_skill("zixia-force", 180);
	set_skill("lingyun-steps", 160);
	set_skill("fuyunshou", 160);

	
	map_skill("sword", "huashan-sword");
	map_skill("force", "zixia-force");
*/
	map_skill("unarmed", "taizu-changquan");

	map_skill("dodge","gaibang-steps");
	map_skill("force", "taizu-force");
	set("inquiry", ([
		"ؤ��"      : "ؤ�ؤ�����¸������зֶ氡��",
		"��ʦ"      : "ؤ�����ڹ��͹�������������ؤ����Ҿ����ˡ�",
		"apprentice": "ؤ�����ڹ��͹�������������ؤ����Ҿ����ˡ�",
		"name"	    : "�ұ���ѩͤ��ֶ��������[÷��Ȩ]��",
		"����"      : "ؤ��������ǡ�³�нǡ���Ϻ����",
		"���߹�"    : "��������ʦ�棬�����ʱ���������˼�һ�档",
]) );

	setup();
//	carry_object(WEAPON_DIR"staff")->wield();
	carry_object(ARMOR_DIR"cloth")->wear();
}
   
void attempt_apprentice(object ob)
{
//	if(ob->query("gender") != "����")
//	{ command("say ��ȥ��Сʦ��ȥ�ɡ�"); return; }

        if(ob->query("int") > 24)
	{
		command("say �����书��Ҫ���õ����壬�����������ɡ�\n" +
		RANK_D->query_respect(ob) + "��ô��������...��������ɵ��İɣ�");
		return;
	}
	if(ob->query("str") < 24)
	{
		command("say �����书��Ҫ���õ����壬�����������ɡ�\n" +
		RANK_D->query_respect(ob) + "��ô������ô������...��������ɵ��İɣ�");
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