inherit NPC;
 
void create()
{
        set_name("��������", ({"zi yi"}));
        set("long", "һλ���ݽ�������������ֽ�վ���š�\n");
        set("gender","Ů��");
        set("title","������");

        set("age",19);
        set("con",30);
        set("str",30);
        set("max_kee",1200);
        set("max_gin",1200);
        set("max_sen",1200);

        set_skill("dodge",100);
        set_skill("longjiao-blade",100);
        set_skill("parry",100);
        set_skill("unarmed",100);
        set_skill("blade",100);
 
        set("combat_exp",50000+random(10000));

        setup();
        carry_object(WEAPON_DIR"sword")->wield();
        carry_object(ARMOR_DIR"cloth")->wear();
}

