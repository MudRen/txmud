//killer.c 钱庄秘道里的黑衣人。
inherit NPC;
void create()
{
        set_name("黑衣杀手", ({"heiyi shashou", "killer"}));
        set("long", "一个全身都包在黑衣里的人，两眼放着精光。\n");
        set("gender","男性");
        set("age",30);
        set("con",20);
        set("str",70);
        set("attitude", "killer");
        set("max_kee",2200);
        set("max_gin",700);
        set("max_sen",700);
        set("max_force",3500);
        set("force",7000);
        set("force_factor",40);

        set_skill("dodge",150);
        set_skill("parry",150);
        set_skill("unarmed",150);
        set_skill("force",150);
        set_skill("blade",150);
        set_skill("ganchan",150);
        set_skill("lianhuan-blade",150);
        set_skill("feilong-quan",150);
//        set_skill("mizong-xinfa",150);
 
        map_skill("dodge","ganchan");        
        map_skill("unarmed","feilong-quan");
        map_skill("blade","lianhuan-blade");
        map_skill("parry","qiuyue-fork");
//      map_skill("force","mizong-xinfa");        

        set("combat_exp",900000);

        setup();
        carry_object(__DIR__"obj/zang-blade")->wield();
        carry_object(__DIR__"obj/teng-armor")->wear();
}

