// shinv.c from mool

inherit NPC;
 
void create()
{
        set_name("��ׯ�Ҷ�", ({"jia ding",}));
        set("long", "һλ���δ�,Ũü����.�����ɨ�������ܡ�\n");
        set("gender","����");
        set("title","�һ�ɽׯ");

       set("chat_chance",2);
        set("chat_msg",({
        "�Ҷ�̾�˿�����:�Ҽ�����Ϊ����ֱ!�벻��ȴ�ܵ���������ų⡣\n"
}));
        set("age",25);
        set("con",30);
        set("str",30);
        set("max_kee",1200);
        set("max_gin",1200);
        set("max_sen",1200);

        set_skill("dodge",200);
        set_skill("longjiao-blade",200);
        set_skill("parry",200);
        set_skill("unarmed",200);
        set_skill("blade",200);

        set("combat_exp",100000+random(30000));

        setup();
        carry_object(WEAPON_DIR"blade")->wield();
        carry_object(ARMOR_DIR"cloth")->wear();
}

