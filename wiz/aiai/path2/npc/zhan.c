// zhan.c

inherit NPC;

void create()
{
        set_name("展飞熊", ({ "zhan feixiong" }) );

        set("title","飞天大圣");

        set("gender", "男性");
        set("age", 37);
        set("long", "这是一位满脸凶像的中年人。\n");

        set("no_exp_gain",1);
        set("cor",50);
        set("combat_exp", 500000);

        set("attitude", "killer");

        set("max_kee",1000);
        set("max_gin",1000);
        set("max_sen",1000);

        set_skill("blade", 220);
        set_skill("unarmed", 200);
        set_skill("parry", 200);
        set_skill("dodge", 200);

        setup();
        carry_object(ARMOR_DIR"cloth")->wear();
        carry_object(WEAPON_DIR"blade")->wield();
}

protected void say_message()
{
        object env;

        if(!objectp(env = environment()))
                return;

        if (query("high_level"))
                return;

        if(is_fighting())
                command("say 竟然几次三番来救人，我看你是活的不耐烦了！\n");
        else
                command("say 你是二弟派来的？我看你是奸细吧！\n");
}

void die()
{
        int exp;
        object winner;

        if (objectp(winner = query_temp("last_damage_from")))
                winner->set("quest/huashan_quest/killed_zfx", 1);

        if (winner->query("quest/huashan_quest/search"))
        {
                if (winner->query("combat_exp", 1)>1000000)
                        exp=to_int(winner->query("combat_exp", 1)/1000000)*200;
                else
                        exp=100+random(100);
                exp+=random(exp);
                tell_object(winner, sprintf("\n你杀死展飞熊获得了 %d 点经验，%d 点潜能。\n",exp,to_int(exp/10)+1));
                winner->add("combat_exp", exp);
                winner->add("potential", to_int(exp/10)+1);
        }

        ::die();
}

