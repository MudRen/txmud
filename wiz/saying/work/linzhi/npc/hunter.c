//hunter.c 林芝村的猎人。
inherit NPC;
void create()
{
        set_name("猎户", ({"lie hu", "hunter"}));
        set("long", "这是一位彪悍的藏族猎户，正在跟周围的人谈论打猎的事情。\n");
        set("gender","男性");
        set("age",35);
        set("con",20);
        set("str",70);
        set("max_kee",2000);
        set("max_gin",700);
        set("max_sen",700);
        set("max_force",2500);
        set("force",2500);
        set("force_factor",30);

        set_skill("dodge",150);
        set_skill("parry",150);
        set_skill("unarmed",150);
        set_skill("force",150);
        set_skill("fork",150);

        set("combat_exp",70000);

        setup();
        carry_object(__DIR__"obj/hunt-fork")->wield();
        carry_object(__DIR__"obj/teng-armor")->wear();
}
