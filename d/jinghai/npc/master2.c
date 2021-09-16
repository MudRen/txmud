// master2.c

inherit NPC;
inherit F_MASTER;

void create()
{
        set_name("林月光", ({ "master yue", "master", "yue" }) );
        set("class","jinghai");
        create_family("靖海派", 1, "创始人");
        set("inquiry",([
        "leave" : (: call_other, __FILE__, "want_to_leave" :),
        "离开" : (: call_other, __FILE__, "want_to_leave" :),
        "叛师" : (: call_other, __FILE__, "want_to_leave" :),
]));

        set("gender", "女性" );
        set("age", 45);
        set("attitude", "peaceful");

        set("long", "这是一位眉清幕秀的中年女子，她就是靖
海派的创始人之一，靖海公的夫人。\n");

        set("combat_exp", 3500000);
        set("str", 40);
        set("per", 29);
        set("max_kee",3500);
        set("max_gin",3500);
        set("max_sen",3500);
        set("force", 5000);
        set("max_force", 5000);
        set("atman", 5000);
        set("max_atman", 5000);
        set("mana", 5000);
        set("max_mana", 5000);
        set("force_factor", 350);

        set_skill("jinghai-force",300);
        set_skill("longjiao-blade",280);
        set_skill("literate",300);
        set_skill("unarmed",280);
        set_skill("dodge",290);
        set_skill("parry",280);
	set_skill("force",300);
	set_skill("blade",280);
	set_skill("canhe-zhi",280);
        //set_skill("jiachuan-shu",300);
        //set_skill("houyi-bow",300);
        //set_skill("bow",280);
        //set_skill("liangqing-xiangyi",300);
        //set_skill("moonlight-sword",300);
        set_skill("sword",300);
        set_skill("bibo-sword",300);
        set_skill("perception",300);
        set_skill("xian-steps",290);

        map_skill("unarmed","canhe-zhi");
        map_skill("force","jinghai-force");
        map_skill("dodge","xian-steps");
        map_skill("parry","bibo-sword");
        map_skill("sword","bibo-sword");

        setup();
        carry_object(WEAPON_DIR"sword")->wield();
        carry_object(ARMOR_DIR"cloth")->wear();

}

void attempt_apprentice(object ob)
{
	if(ob->query("class") != "jinghai")
		return;

        if(ob->query("gender") == "男性")
        {
                command("say 妾身不收男弟子，去问问我相公吧。");
                return;
        }
/*
        command("shake");
        return;

        if(!ob->query_temp("pass_shengji_quest"))
                return;
*/
	if(ob->query_skill("jinghai-force",1) < 200)
	{
		command("say 你的靖海神功火候不够，回去练练再说吧。");
		return;
	}

        else
        {
                command("smile");
                command("say 很好，" + RANK_D->query_respect(ob) + "多加努力，他日必定有成。\n");
                command("recruit " + ob->query("id") );
        }
}

int recruit_apprentice(object ob)
{
        ::recruit_apprentice(ob);
        ob->set("class", "jinghai");
        return 1;
}

