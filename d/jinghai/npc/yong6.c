inherit NPC;

void create()
{
        set_name("���¿���", ({"bai yi","bai"}));
        set("long", "һλ��Ŀ��ڵĴ󺺡������ɨ�������ܡ�\n");
        set("gender","����");
        set("title","������");

        set("age",25);
        set("con",30);
        set("str",20);
        set("max_kee",500);
        set("max_gin",500);
        set("max_sen",500);

        set_skill("dodge",50);
        set_skill("longjiao-blade",50);
        set_skill("parry",50);
        set_skill("unarmed",50);
        set_skill("blade",50);
 
        set("combat_exp",10000+random(3000));
 
        setup();
        carry_object(WEAPON_DIR"blade")->wield();
        carry_object(ARMOR_DIR"cloth")->wear();
}

