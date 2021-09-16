inherit NPC;
inherit F_MASTER;

void create()
{
        set_name("赵之玄", ({ "master zhao", "master", "zhao" }) );
        set("class","jinghai");
        create_family("靖海派", 2, "弟子青龙堂堂主");
        set("inquiry",([
        "leave" : (: call_other, __FILE__, "want_to_leave" :),
        "离开" : (: call_other, __FILE__, "want_to_leave" :),
        "叛师" : (: call_other, __FILE__, "want_to_leave" :),
]));

        set("gender", "男性" );
        set("age", 30);
        set("attitude", "peaceful");

        set("long", "皮盔竹甲，身形高大，一副武将打扮。
他就是靖海派祖师的三弟子。\n");

        set("combat_exp", 2000000);
        set("str", 50);
        set("per", 29);
        set("max_kee",2200);
        set("kee",2200);
        set("max_gin",2200);
        set("gin",2200);
        set("max_sen",2200);
        set("sen",2200);
        set("force", 2800);
        set("max_force", 2800);
        set("atman", 2800);
        set("max_atman", 2800);
        set("mana", 2800);
        set("max_mana", 2800);
        set("force_factor", 100);


        set_skill("jinghai-force",200);
        set_skill("longjiao-blade",200);
        set_skill("literate",255);
        set_skill("unarmed",200);
        set_skill("dodge",200);
        set_skill("parry",200);
        set_skill("force",200);
        set_skill("jiachuan-shu",220);
        set_skill("houyi-bow",240);
        set_skill("bow",220);
        set_skill("liangqing-xiangyi",205);
        set_skill("moonlight-sword",200);
        set_skill("sword",200);
        set_skill("bibo-sword",200);
        set_skill("perception",200);
        set_skill("xian-steps",220);

        map_skill("force","jinghai-force");
        map_skill("dodge","xian-steps");
        map_skill("parry","liangqing-xiangyi");
        map_skill("sword","liangqing-xiangyi");

        setup();
        carry_object(WEAPON_DIR"sword")->wield();
        carry_object(ARMOR_DIR"cloth")->wear();
 
}

 
void attempt_apprentice(object ob)
{
        if(ob->query("gender") == "女性")
        {
                command("say 我不收女弟子，你去问问我的师姐们吧。");
                command("say 我在忙着操练水勇，没空授徒。");
                return;
        }

        command("shake");
        return;

        if(!ob->query_temp("pass_shengji_quest"))
                return;
        else
        {
                command("smile");
                command("say 不错，" + RANK_D->query_respect(ob) + "多加努力，他日必有所成。\n");
                command("recruit " + ob->query("id") );
        }
}

int recruit_apprentice(object ob)
{
        ::recruit_apprentice(ob);
        ob->set("class", "jinghai");
        return 1;
}

