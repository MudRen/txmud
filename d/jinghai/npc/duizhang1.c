inherit NPC;
 
void create()
{
        set_name("�����ӳ�", ({"duei zhang","duei"}));
        set("long", "һλ��Ŀ��ڵĴ󺺡������ɨ�������ܡ�\n");
        set("gender","����");
        set("title","������");

        set("age",25);
        set("con",30);
        set("str",30);
        set("max_kee",1200);
        set("max_gin",1200);
        set("max_sen",1200);

        set_skill("dodge",200);
        set_skill("longjiao-blade",100);
        set_skill("parry",200);
        set_skill("unarmed",200);
        set_skill("blade",200);
 
	map_skill("blade","longjiao-blade");

        set("combat_exp",500000+random(30000));
 
        setup();
        carry_object(WEAPON_DIR"blade")->wield();
        carry_object(ARMOR_DIR"cloth")->wear();
}

