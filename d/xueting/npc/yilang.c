inherit NPC;

void create()
{
        set_name("����һ��", ({ "yi lang", "le", "liu sheng yilang" }) );
        set("gender", "����" );
        set("title","�ձ�����");
        set("age", 38);
        set("attitude", "peaceful");

        set("long", "һ������������ձ����ˡ���˵�ھ��ǵ�Ѳ�������˼����㹤��
ѧ�����ֹ���׼�����������������ء� \n\n");

        set("combat_exp", 3000000);
        set("str", 60);
        set("per", 15);
        set("max_kee",3500);
        set("kee",3500);
        set("max_gin",3500);
        set("gin",3500);
        set("max_sen",3500);
        set("sen",3500);
        set("force", 5000);
        set("max_force", 5000);
        set("atman", 5000);
        set("max_atman", 5000);
        set("mana", 5000);
        set("max_mana", 5000);
        set("force_factor", 300);

        set_skill("jinghai-force",300);
        set_skill("longjiao-blade",280);
        set_skill("literate",300);
        set_skill("unarmed",260);
        set_skill("dodge",280);
        set_skill("parry",280);
        set_skill("force",300);
        set_skill("jiachuan-shu",300);
        set_skill("houyi-bow",300);
        set_skill("bow",280);
        set_skill("liangqing-xiangyi",300);
        set_skill("moonlight-sword",300);
        set_skill("sword",300);
        set_skill("bibo-sword",300);
        set_skill("perception",300);
        set_skill("xian-steps",280);

        map_skill("force","jinghai-force");
        map_skill("dodge","xian-steps");
        map_skill("parry","liangqing-xiangyi");
        map_skill("sword","liangqing-xiangyi");


	set("chat_chance_combat", 15);
        set("chat_msg_combat", ({
                (: perform_action, "dodge.changen" :),
                "����һ�ɺȵ�������������������־͸���\n",
                "����һ�ɺȵ�����֪ų���Ȼ��Һ��ұ��ԣ����ˣ����ˣ�\n"
        }) );
        
        set("chat_chance", 7);
        set("chat_msg", ({
        "����һ�ɰ����Ķ���˵����ų�򣬸Һ��ұ���һ���� \n",
        }) );
        set("inquiry", ([
              "�ձ�" : "�ٺ٣���Ľ���ǣ��Ǿʹ�����Ļ����������...",      
              "����" : "�˸����������ǻ����ˡ�", ]) );



        setup();
        add_money("silver", 290);
        carry_object(WEAPON_DIR"sword")->wield();
        carry_object(ARMOR_DIR"cloth")->wear();

}
