inherit NPC;
 
void create()
{
        set_name("男仆", ({"pu ren",}));
        set("long", "一位瘦弱的青年男子,低着头静静的站在那里。\n");
        set("gender","男性");
        set("title","靖海山庄");

        set("age",25);
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

        set("combat_exp",10000+random(10000));

        setup();
        carry_object(ARMOR_DIR"cloth")->wear();
}

