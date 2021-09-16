inherit NPC;
inherit F_MASTER;

void create()
{
        set_name("���", ({ "master gang", "master", "gang" }) );
        set("class","jinghai");
        create_family("������", 2, "�����");
        set("inquiry",([
        "leave" : (: call_other, __FILE__, "want_to_leave" :),
        "�뿪" : (: call_other, __FILE__, "want_to_leave" :),
        "��ʦ" : (: call_other, __FILE__, "want_to_leave" :),
]));

        set("gender", "����" );
        set("age", 27);
        set("attitude", "peaceful");

        set("long", "���³��ۣ���Ŀ���㣬һ��������硣
�����Ǿ��������Ŵ���ӡ���Сʦ����С��
÷�����������ã�������Ϊ�򸾡���Ϊ��
����Ϊ������Ľ��һ�����¡�\n");

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
        set("chat_chance",2);
        set("chat_msg",({
        "������Ű��޵�ͮ���֣������ĬĬ���ӡ�Ŀ�����к���ǧ�����飬������⡣\n"
}));

        set_skill("jinghai-force",250);
        set_skill("longjiao-blade",200);
        set_skill("literate",255);
        set_skill("unarmed",200);
        set_skill("dodge",200);
        set_skill("parry",200);
        set_skill("force",200);
        set_skill("jiachuan-shu",220);
        set_skill("houyi-bow",240);
        set_skill("bow",240);
        set_skill("liangqing-xiangyi",255);
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
        carry_object(WEAPON_DIR"sword")->wield();
        carry_object(ARMOR_DIR"cloth")->wear();

}

 
void attempt_apprentice(object ob)
{
        if(ob->query("gender") == "Ů��")
        {
                command("say �Ҳ���Ů���ӣ����Ż���Ҽ���,��ȥ���������Űɡ�");
                command("shy");
                return;
        }

        command("shake");
        return;

        if(!ob->query_temp("pass_shengji_quest"))
                return;
        else
        {
                command("smile");
                command("say ����" + RANK_D->query_respect(ob) + "���Ŭ�������ձ������ɡ�\n");
                command("recruit " + ob->query("id") );
        }
}

int recruit_apprentice(object ob)
{
        ::recruit_apprentice(ob);
        ob->set("class", "jinghai");
        return 1;
}

