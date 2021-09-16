// xiuxiu.c

inherit NPC;

int is_hs_quest_xiuxiu() { return 1; }
protected object master;
protected void say_message();
protected int free;

object query_my_master() { return master; }

void create()
{
        set_name("秀秀", ({ "xiu xiu" }) );
        set("gender", "女性");
        set("age", 17);
        set("long", "这是一位漂亮的农家女孩。\n");

        set("no_exp_gain",1);
        set("no_return_home",1);
        set("per",30);

        set("attitude", "friendly");

        set("chat_chance", 5);
        set("chat_msg", ({
                (: say_message :),
        }) );

        set("max_kee",800);
        set("max_gin",600);
        set("max_sen",600);

        setup();
        carry_object(ARMOR_DIR"cloth")->wear();
}

void been_free(object me)
{
        free = 1;

        if(!objectp(me))
                return;

        master = me;
        set_leader(me);
        command("say 上面的石板推(push)开就是出口了，您能不能送我回家，呜。。。");
}

protected void say_message()
{
        object env;

        if(!objectp(env = environment()))
                return;

        if(!free)
                command("say 这位侠士救救我帮我砸(za)开锁链吧，我爷爷还在家等着我呢。。。\n");

        else if(env->is_path2_dl())
        {
                if(env->query("exits/up"))
                        command("say 这位侠士能不能送我回家呀，呜，呜。。。");
                else
                        command("say 上面的石板推(push)开就是出口了，救救我吧。。。");
        }
}

