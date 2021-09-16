// master2.c
// by dicky

#include <ansi.h>
inherit NPC;
inherit F_MASTER;

string ask_mimi();

void create()
{
	set_name("̤ѩ��Զ", ({ "taxue jingyuan","jingyuan","master"}) );
        set("class","taxue");
        create_family("̤ѩɽׯ", 1, "����");
        set("title",HIW"����ѩ��"NOR);	
	set("nickname",HIY"̤ѩɽׯׯ��"NOR);

	set("age", 53);
	set("long", "���³��ۣ���Ŀ���㣬һ��������硣������̤ѩɽׯׯ����\n");
	set("attitude","heroism");
	set("gender", "����" );

        set("combat_exp", 4000000);
        set("str", 80);
        set("per", 30);
        set("max_kee",4000);
        set("kee",4000);
        set("max_gin",4000);
        set("gin",4000);
        set("max_sen",4000);
        set("sen",4000);
        set("force", 4000);
        set("max_force", 4000);
        set("atman", 4000);
        set("max_atman", 4000);
        set("mana", 4000);
        set("max_mana", 4000);
        set("force_factor", 200);
	set("chat_chance_combat",40);
	set("chat_msg_combat",({
		(: perform_action, "sword.qicai" :),
	}));

       set("inquiry", ([
                "����" : (: ask_mimi :),
                 "mimi" : (: ask_mimi :),
       ]));

        set_skill("taxue-force",250);
        set_skill("fenghui-sword",250);
        set_skill("xueli-steps",250);
        set_skill("chuanyun-zhang",250);
        set_skill("unarmed",250);
        set_skill("literate",200);
//        set_skill("zhouyi",200);
        set_skill("dodge",250);
        set_skill("parry",250);
        set_skill("force",250);
        set_skill("sword",250);

        map_skill("force","taxue-force");
        map_skill("sword","fenghui-sword");
        map_skill("dodge","xueli-steps");
        map_skill("unarmed","chuanyun-zhang");
        map_skill("parry","fenghui-sword");	

        setup();
        carry_object(WEAPON_DIR"sword")->wield();
        carry_object(__DIR__"obj/jinduan")->wear();

}


void attempt_apprentice(object ob)
{
	if(ob->query("class") != "taxue")
		return;

	if(ob->query_skill("taxue-force",1) < 180)
	{
		command("say ���̤ѩ�񹦻�򲻹�����ȥ������˵�ɡ�");
		return;
        }

	if(ob->query_skill("fenghui-sword",1) < 180)
	{
		command("say ��ķ��ѩ�轣ѧ�û�򲻹�����ȥ������˵�ɡ�");
		return;
        }

	if(ob->query_skill("dodge",1) < 180)
	{
		command("say ��Ļ����Ṧ��ϰ�û�򲻹�����ȥ������˵�ɡ�");
		return;
        }

	if(ob->query("family/master_id") == "taxue rongbo")
	{
		command("say ��Ц�ˣ���������ʦָ�㣬�α����������أ�");
		return;
        }

	command("smile");
	command("say �ܺã�" + RANK_D->query_respect(ob) + "���Ŭ�������ձ������ɡ�\n");
	command("recruit " + ob->query("id") );
}

int recruit_apprentice(object ob)
{
        ::recruit_apprentice(ob);
        ob->set("class", "taxue");
        return 1;
}

string ask_mimi()
{
        object ob;
        ob = this_player();

        if(ob->query("class")!="taxue")
        return "�Բ���"+ob->name()+"����û��ʲô���ܺø����㣡";

        if(ob->query_temp("taxue/ask_master"))
        return "��ղŲ����ʹ���ô����ô�����ˣ�";

	ob->set_temp("taxue/ask_master",1);
        return ""+ob->name()+"���ں�ɽ��ɽ����ס�ű��ŵ�һλǰ��������ܵõ�����ָ�㣬������������ң�";
}
