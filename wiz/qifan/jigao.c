// jigao.c

inherit NPC;

void create()
{
        set_name("�Ƽ̸�", ({ "tang jigao","tg" }) );

        set("class","tangmen");
        create_family("��������", 17, "����");

        set_auto_recover(1);

        set("gender", "����" );
        set("age", 36);
        set("long", "�Ƽ̸��Ǳ����Ķ����ӣ���Ȼ����
�����Ƽ�Զ����������ʵ��ʮ��
����������ߵ�һ����\n");

        set("combat_exp", 2000000);
        set("str", 37);
        set("max_kee",2000);
        set("kee",2000);
        set("max_gin",2000);
        set("gin",2000);
        set("max_sen",2000);
        set("sen",2000);
        set("force", 6000);
        set("max_force", 6000);
        set("atman", 4000);
        set("max_atman", 4000);
        set("mana", 4000);
        set("max_mana", 4000);
        set("force_factor", 150);
        set("chat_chance_combat",3);
        set("chat_msg_combat",({
                (: perform_action, "unarmed.san" :),
}));
        set_skill("literate",220);
        set_skill("unarmed",220);
        set_skill("dodge",220);
        set_skill("parry",220);
        set_skill("force",220);
        set_skill("magic",220);
        set_skill("spells",220);
        set_skill("sword",220);
        set_skill("throwing",220);
        set_skill("perception",220);

        set_skill("liuhua-sword", 150);
        set_skill("tang-force", 220);
        set_skill("tang-du", 200);
        set_skill("tianchan-steps", 220);
        set_skill("wuying-zhang", 220);
        set_skill("medicine", 160);

        //map_skill("medicine","tang-du");
        map_skill("unarmed","wuying-zhang");
        map_skill("throwing","wuying-zhang");
        map_skill("force","tang-force");
        map_skill("dodge","tianchan-steps");
        map_skill("sword","liuhua-sword");

        setup();

        carry_object(WEAPON_DIR"zhen")->wield();
        carry_object(WEAPON_DIR"zhen")->wield();
        carry_object(WEAPON_DIR"zhen")->wield();
        carry_object(WEAPON_DIR"zhen")->wield();
        carry_object(WEAPON_DIR"zhen")->wield();
        carry_object(WEAPON_DIR"zhen")->wield();
        carry_object(WEAPON_DIR"zhen")->wield();
        carry_object(WEAPON_DIR"zhen")->wield();
        carry_object(WEAPON_DIR"zhen")->wield();
        carry_object(WEAPON_DIR"zhen")->wield();
        carry_object(WEAPON_DIR"zhen")->wield();
        carry_object(WEAPON_DIR"zhen")->wield();
        carry_object(WEAPON_DIR"zhen")->wield();
        carry_object(WEAPON_DIR"zhen")->wield();
        carry_object(WEAPON_DIR"zhen")->wield();
        carry_object(WEAPON_DIR"zhen")->wield();
        carry_object(WEAPON_DIR"zhen")->wield();
        carry_object(WEAPON_DIR"zhen")->wield();
        carry_object(WEAPON_DIR"zhen")->wield();

        carry_object(ARMOR_DIR"cloth")->wear();
}