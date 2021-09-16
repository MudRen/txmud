// zhan.c

inherit NPC;

void create()
{
        set_name("չ����", ({ "zhan feixiong" }) );

        set("title","�����ʥ");

        set("gender", "����");
        set("age", 37);
        set("long", "����һλ��������������ˡ�\n");

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
                command("say ��Ȼ�������������ˣ��ҿ����ǻ�Ĳ��ͷ��ˣ�\n");
        else
                command("say ���Ƕ��������ģ��ҿ����Ǽ�ϸ�ɣ�\n");
}

void die()
{
        int exp;
        object winner;

        if (objectp(winner = query_temp("last_damage_from")))
                winner->set("quest/huashan_quest/killed_zfx", 1);

        if (winner->query("quest/huashan_quest/search"))
        {
                tell_object(winner, "��ɱ��չ���ۻ����һЩ���顣\n");
                if (winner->query("combat_exp", 1)>1000000)
                        exp=to_int(winner->query("combat_exp", 1)/1000000)*200+random(200);
                else
                        exp=100+random(100);
                winner->add("combat_exp", exp);
        }

        ::die();
}

