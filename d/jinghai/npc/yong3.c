inherit NPC;
 
void create()
{
        set_name("�̽�����", ({"lv bing",}));
        set("long", "һλ��Ŀ��ڵĴ󺺡������ɨ�������ܡ�\n");
        set("gender","����");
        set("title","����կ");

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
 
        set("combat_exp",400000+random(30000));

        setup();
        carry_object(WEAPON_DIR"blade")->wield();
        carry_object(ARMOR_DIR"cloth")->wear();
}