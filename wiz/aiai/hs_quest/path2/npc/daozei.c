// daozei.c

inherit NPC;

string *xx_place_name = ({
        "长安城",
        "左家村",
        "侯集镇",
        "天水镇",
});

string *xx_place = ({
        "/d/changan/sroad1",
        "/d/zuojiacun/lu2",
        "/d/houjizhen/tulu2",
        "/d/tianshui/wroad2",
});

string *out_place = ({
        "/d/changan/eroad2",
        "/d/zuojiacun/ju1",
        "/d/houjizhen/hean2",
        "/d/tianshui/caizhu3",
});

void create()
{
        set_name("盗贼", ({ "dao zei" }) );

        set("title","小头目");

        set("gender", "男性");
        set("age", 27);
        set("long", "这是一位满脸凶像的年轻人。\n");

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

void unconcious()
{
        int i;
        string xxn, xxp;
        object winner = query_temp("last_damage_from");
        object ob=this_object(), npc;

        if(!random(3))
        {
                i=random(sizeof(xx_place_name));
                xxn=xx_place_name[i];
                xxp=xx_place[i];
                winner->remove_all_enemy();
                ob->remove_all_enemy();
                ob->set("kee",100);
                message_vision("$N吓的急忙跪地求饶。\n",ob);
                command("say 好汉饶小的一命，我大哥出去做买卖，让小的过一阵子去看秀秀，\n"
                        +"还说别让人给救走了。秀秀现在被关在"+xxn+"，那附近有个接头的，他可以\n"
                        +"带您去关秀秀的地方。");
                message_vision("\n$N说完便一溜烟的跑了。\n",ob);

                npc=new(__DIR__"guide");
                npc->set_master(winner->query("id"));
                npc->move(xxp);
                winner->set("quest/huashan_quest/search", 1);
                winner->set("quest/huashan_quest/my_place", out_place[i]);
                winner->set("quest/huashan_quest/reward", 
                        to_int((int)winner->query("quest/huashan_quest/reward", 1)*2.5));
                destruct(ob);
        }
        else
        {
                ::unconcious();
        }
}

void die()
{
        int i;
        //int exp;
        object ob;
        //object me=this_player();
        object winner = query_temp("last_damage_from");
        
/*
        if (random(2))
        {
                for (exp=0; exp<random(4); exp++)
                {
                        ob = new(__DIR__"loulou");
                        ob->move(environment());
                }
                if (exp)
                        message_vision("\n$N正在战斗着，忽然展飞雄带手下回来了！\n",me);
                else
                        message_vision("\n$N正在战斗中，展飞雄突然回来了！\n",me);
                ob = new(__DIR__"zhan");
                ob = me->query("combat_exp");
                if(exp > ob->query("combat_exp"))
                        ob->set("combat_exp",exp);
                ob->move(environment());
        message_vision("\n$N朝着$n喊道：“活腻味了敢跑这来劫人！找死！”\n",ob,me);
        ob->kill_ob(me);
        me->kill_ob(ob);
                new(__DIR__"obj/key")->move(ob);
        }
        else 
        {
*/
                if (random(2)) 
                {
                        new(__DIR__"obj/key")->move(this_object());
                                winner->set_temp("hs_quest_jail_enter", 1);
                }
                else
                {
                        i=random(sizeof(xx_place_name));
                        ob=new(__DIR__"obj/xin");
                        ob->set("for_xiuxiu", 1);
                        ob->set_place(xx_place_name[i]);
                        ob->move(this_object());
                        ob=new(__DIR__"guide");
                        ob->set_master(winner->query("id"));
                        ob->move(xx_place[i]);
                        winner->set("quest/huashan_quest/search", 1);
                        winner->set("quest/huashan_quest/my_place", out_place[i]);
                        winner->set("quest/huashan_quest/reward", 
                        to_int((int)winner->query("quest/huashan_quest/reward", 1)*3));
                }
//      }

        ::die();
}

