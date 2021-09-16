// dt_beggar.c

inherit NPC;

void create()
{
        set_name("乞丐", ({"beggar"}));
        set("class", "gaibang");

        set("gender", "男性");
        set("age", 25+random(30));
        set("long","这个乞丐蓬头垢面，穿得破破烂烂的。\n");
        set("attitude", "peaceful");
        set("str", 40);
        set("cor", 20);
        set("int", 20);
        set("con", 20);
        set("kar", 20);
        set("per", 20);

        set("kee", 400);
        set("max_kee", 400);
        set("gin", 200);
        set("max_gin", 200);
        set("sen", 200);
        set("max_sen", 200);
        set("force", 200);
        set("max_force", 200);
        set("atman", 0);
        set("max_atman", 0);
        set("mana", 0);
        set("max_mana", 0);
        set("force_factor", 2);
        set("combat_exp", 20000);

        set_skill("begging", 100);
        set_skill("unarmed", 50);
        set_skill("force", 50);
        set_skill("dodge", 50);
        set_skill("parry", 50);

        set("inquiry", ([
        ]));

        set("is_beggar",1);
        set("chat_chance", 10);
        set("chat_msg", ({
                "乞丐说道：好心的大爷哪～ 赏我要饭的几文钱吧～\n",
                "乞丐使劲伸了个懒腰，打了个哈欠。\n",
                (: random_move :)
        }) );

        setup();
        carry_object(__DIR__"obj/cloth")->wear();
        carry_object(__DIR__"obj/budai_1")->wear();
}

int accept_object(object me, object obj)
{
        command("smile");
        command("say 多谢这位" + RANK_D->query_respect(me) + "，您好心一定会有好报的！");
        return 1;
}

int accept_fight(object me)
{
        command("say " + RANK_D->query_respect(me) + "饶命！小的这就离开！\n");
        return 0;
}

