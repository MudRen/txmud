inherit NPC;

void create()
{
        set_name("�ֳ���", ({ "le changsheng", "le", "changsheng" }) );
        set("gender", "����" );
        set("title","������");
        set("age", 38);
        set("attitude", "peaceful");

        set("long", "����һλ��ò��ª�����꺺�ӣ�һ�����ࡣ
û���˼���������Ц�ݣ�������
����������������ɱ��֮һ������\n");

        set("combat_exp", 4000000);
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

        setup();
        carry_object(WEAPON_DIR"sword")->wield();
        carry_object(ARMOR_DIR"cloth")->wear();

}

 

