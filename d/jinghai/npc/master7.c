// master7.c

inherit NPC;
inherit F_MASTER;

void create()
{
        set_name("�˳�", ({ "master chu", "master", "chu" }) );
        set("class","jinghai");
        set("title","[��ݲ��������]");
        set("inquiry",([
        "leave" : (: call_other, __FILE__, "want_to_leave" :),
        "�뿪" : (: call_other, __FILE__, "want_to_leave" :),
        "��ʦ" : (: call_other, __FILE__, "want_to_leave" :),
]));

        set("gender", "����" );
        set("age", 28);
        set("attitude", "heroism");

        set("long", "����Ǿ�����ʼ�˷򸾵�С���ӡ�
�����Ǿ����������������������е��塣\n");

        set("combat_exp", 1600000);
        set("str", 40);
        set("per", 26);
        set("max_kee",2000);
        set("kee",2000);
        set("max_gin",2000);
        set("gin",2000);
        set("max_sen",2000);
        set("sen",2000);
        set("force", 2800);
        set("max_force", 2500);
        set("atman", 2500);
        set("max_atman", 2500);
        set("mana", 2500);
        set("max_mana", 2500);
        set("force_factor", 50);

        set_skill("jinghai-force",220);
        set_skill("longjiao-blade",220);
	set_skill("literate",250);
	set_skill("unarmed",200);
	set_skill("dodge",220);
	set_skill("parry",200);
	set_skill("canhe-zhi",220);
	set_skill("force",200);
	//set_skill("jiachuan-shu",220);
	//set_skill("houyi-bow",220);
	//set_skill("bow",240);
	//set_skill("liangqing-xiangyi",255);
	set_skill("moonlight-sword",200);
	set_skill("sword",200);
	set_skill("bibo-sword",200);
	set_skill("perception",200);
	set_skill("xian-steps",220);

        map_skill("force","jinghai-force");
        map_skill("dodge","xian-steps");
        map_skill("parry","liangqing-xiangyi");
        map_skill("sword","liangqing-xiangyi");

        setup();
        carry_object(__DIR__"obj/qiuyi")->wear();
        carry_object(__DIR__"obj/kao")->wear();
 
}

 
void attempt_apprentice(object ob)
{
        if(ob->query("gender") == "Ů��")
        {
                command("say �Ҳ���Ů���ӣ�ȥ�����ҵ�ʦ���ǰ�.....��");
                command("hehe");
                return;
        }

        command("shake");
        return;

        if(!ob->query_temp("pass_shengji_quest"))
                return;
        else
        {
                command("smile");
                command("say ������ԣ�" + RANK_D->query_respect(ob) + "���Ŭ�������ձ������ɡ�\n");
                command("recruit " + ob->query("id") );
        }
}

int recruit_apprentice(object ob)
{
        ::recruit_apprentice(ob);
        ob->set("class", "jinghai");
        return 1;
}

