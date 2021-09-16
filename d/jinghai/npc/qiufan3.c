inherit NPC;
 
void create()
{
        set_name("������", ({"si yi","yi"}));
        set("long", "����һ��������������꺺�ӡ�\n");
        set("gender","����");
        set("title","[����]");

        set("age",29);
        set("con",30);
        set("str",40);
        set("max_kee",2500);
        set("max_gin",2500);
        set("max_sen",2500);
        set("max_force", 4000);
        set("force", 4000);
        set("force_factor", 200);
        set("attitude", "aggressive");

        set("chat_chance",5);
        set("chat_msg",({
        "������������:........�Ҷ�.....����\n"
}));

        set_skill("dodge",250);
        set_skill("longjiao-blade",250);
        set_skill("parry",250);
        set_skill("unarmed",250);
        set_skill("force",250);
        set_skill("xian-steps",280);
        set_skill("canhe-zhi",300);
        set_skill("jinghai-force",280);
        set_skill("blade",250);

        map_skill("unarmed","canhe-zhi");
        map_skill("dodge","xian-steps");
        map_skill("parry","longjiao-blade");
        map_skill("blade","longjiao-blade");
        map_skill("force","jinghai-force");

        set("combat_exp",100000+random(10000));

        setup();
        carry_object(__DIR__"obj/qiuyi")->wear();
        carry_object(__DIR__"obj/kao")->wear();
}

