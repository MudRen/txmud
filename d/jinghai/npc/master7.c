// master7.c

inherit NPC;
inherit F_MASTER;

void create()
{
        set_name("邓楚", ({ "master chu", "master", "chu" }) );
        set("class","jinghai");
        set("title","[身份不详的囚犯]");
        set("inquiry",([
        "leave" : (: call_other, __FILE__, "want_to_leave" :),
        "离开" : (: call_other, __FILE__, "want_to_leave" :),
        "叛师" : (: call_other, __FILE__, "want_to_leave" :),
]));

        set("gender", "男性" );
        set("age", 28);
        set("attitude", "heroism");

        set("long", "这就是靖海创始人夫妇的小儿子。
他就是靖海派掌门六个弟子中排行第五。\n");

        set("combat_exp", 1600000);
        set("str", 40);
        set("per", 26);
        set("max_kee",2000);
        set("kee",2000);
        set("max_gin",2000);
        set("gin",2000);
        set("max_sen",2000);
        set("sen",2000);
        set("force", 2800);
        set("max_force", 2500);
        set("atman", 2500);
        set("max_atman", 2500);
        set("mana", 2500);
        set("max_mana", 2500);
        set("force_factor", 50);

        set_skill("jinghai-force",220);
        set_skill("longjiao-blade",220);
	set_skill("literate",250);
	set_skill("unarmed",200);
	set_skill("dodge",220);
	set_skill("parry",200);
	set_skill("canhe-zhi",220);
	set_skill("force",200);
	//set_skill("jiachuan-shu",220);
	//set_skill("houyi-bow",220);
	//set_skill("bow",240);
	//set_skill("liangqing-xiangyi",255);
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
        carry_object(__DIR__"obj/qiuyi")->wear();
        carry_object(__DIR__"obj/kao")->wear();
 
}

 
void attempt_apprentice(object ob)
{
        if(ob->query("gender") == "女性")
        {
                command("say 我不收女弟子，去问问我的师姐们吧.....。");
                command("hehe");
                return;
        }

        command("shake");
        return;

        if(!ob->query_temp("pass_shengji_quest"))
                return;
        else
        {
                command("smile");
                command("say 还算可以，" + RANK_D->query_respect(ob) + "多加努力，他日必有所成。\n");
                command("recruit " + ob->query("id") );
        }
}

int recruit_apprentice(object ob)
{
        ::recruit_apprentice(ob);
        ob->set("class", "jinghai");
        return 1;
}

