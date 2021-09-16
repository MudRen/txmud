inherit NPC;

void create()
{
        set_name("白衣看守", ({"bai yi","bai"}));
        set("long", "一位面目黝黑的大汉。警惕的扫视这四周。\n");
        set("gender","男性");
        set("title","无名堡");

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

