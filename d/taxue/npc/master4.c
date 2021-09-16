// master4.c
// by dicky

#include <ansi.h>
inherit NPC;
inherit F_MASTER;

// string ask_title();

void create()
{
        set_name("̤ѩ����", ({ "taxue qingyun", "master", "qingyun" }) );
        set("class","taxue");
        set("nickname",HIG"ѩ�зɺ�"NOR);
        create_family("̤ѩɽׯ", 2, "����");

        set("gender", "����" );
        set("age", 27);
        set("attitude", "peaceful");
        set("long", "���³��ۣ���Ŀ���㣬һ��������硣
		������̤ѩɽׯ���Ŵ���ӡ�Сʱ���Ǹ��¶���
		������̤ѩɽׯׯ�����������������书��
		����ѧ���������ڳ�Ϊ��������һ�����ĸ��֣�
		�����˳���Ϊ��ѩ�зɺ�����\n"
	);

        set("combat_exp", 2000000);
        set("str", 50);
        set("per", 29);
        set("max_kee",2200);
        set("kee",2200);
        set("max_gin",2200);
        set("gin",2200);
        set("max_sen",2200);
        set("sen",2200);
        set("force", 2800);
        set("max_force", 2800);
        set("atman", 2800);
        set("max_atman", 2800);
        set("mana", 2800);
        set("max_mana", 2800);
        set("force_factor", 100);

        set_skill("taxue-force",180);
        set_skill("fenghui-sword",180);
        set_skill("xueli-steps",180);
        set_skill("chuanyun-zhang",180);
        set_skill("unarmed",180);
        set_skill("literate",150);
        set_skill("dodge",180);
        set_skill("parry",180);
        set_skill("force",180);
        set_skill("sword",180);

        map_skill("force","taxue-force");
        map_skill("sword","fenghui-sword");
        map_skill("dodge","xueli-steps");
        map_skill("unarmed","chuanyun-zhang");
        map_skill("parry","fenghui-sword");	

//	set("inquiry", ([
//		"title": (: ask_title :),
//	]));
	

        setup();
        carry_object(WEAPON_DIR"sword")->wield();
        carry_object(ARMOR_DIR"cloth")->wear();
}

 
void attempt_apprentice(object ob)
{
	string startxx;
	startxx= "/d/taxue/dating";

        if( ob->query("class") == "taxue")
        {
		command("say ��Ц�ˣ���������ʦָ�㣬�α����������أ�");
		return;
        }

        if( ob->query("title") != "��ͨ����")
        {
		command("say ��̤ѩɽׯ������������ͽ���뾡���뿪��");
		return;
        }

	if( (ob->query("per") < 25) || (ob->query("age") > 14) )
	{
		command("say ��̤ѩɽׯ������ֻ������Ư���ĺ��ӣ��㻹���߰ɡ�");
		return;
	}

                command("smile");
                command("say ����" + RANK_D->query_respect(ob) + "���Ŭ�������ձ������ɡ�\n");
                command("recruit " + ob->query("id") );

                ob->set("startroom",startxx);
                ob->save();
}

int recruit_apprentice(object ob)
{
        ::recruit_apprentice(ob);
        ob->set("class", "taxue");
        return 1;
}

/*
string ask_title()
{
        object ob;
        ob = this_player();

        if(ob->query("class")!="taxue")
		return "����������������Ǳ��ŵ��ӣ�\n";

	if(ob->query("family/master_id") != "taxue rongbo")
		return "�Ǻǣ����ʵ�ھ�����ô�����ȥ��Ŭ���ɣ�\n";

        if(ob->query("title")!=HIW"�н���ѩ�²�����"NOR)
	ob->set("title",HIW"�н���ѩ�²�����"NOR);
	return "�Ǻǣ��ǲ���ͷ���д���ѽ�������ϸ������������\n";
}
*/

