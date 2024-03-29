// master4.c

inherit NPC;
inherit F_MASTER;

string ask_kao(object me);

void create()
{
        set_name("钟秀雨", ({ "master zhong", "master", "zhong" }) );
        set("class","jinghai");
        create_family("靖海派", 3, "弟子朱雀堂堂主");
        set("inquiry",([
        "leave" : (: call_other, __FILE__, "want_to_leave" :),
        "离开" : (: call_other, __FILE__, "want_to_leave" :),
        "叛师" : (: call_other, __FILE__, "want_to_leave" :),
	"kao" : (: ask_kao :),
	"镣铐" : (: ask_kao :),
]));

        set("gender", "女性" );
        set("age", 25);
        set("attitude", "peaceful");

        set("long", "这是一位在江湖中历练多年，让人感觉很
处世老练精干的年轻女子，她就是靖海朱雀堂堂主。\n");

        set("combat_exp", 800000);
        set("str", 30);
        set("per", 21);
        set("max_kee",2000);
        set("max_gin",2000);
        set("max_sen",2000);

        set("force", 4500);
        set("max_force", 4500);
        set("atman", 2500);
        set("max_atman", 2500);
        set("mana", 2500);
        set("max_mana", 2500);
        set("force_factor", 150);

        set_skill("jinghai-force",110);
        set_skill("longjiao-blade",100);
	set_skill("blade",120);
        set_skill("literate",120);
        set_skill("unarmed",120);
        set_skill("dodge",120);
        set_skill("parry",120);
        set_skill("force",120);
	//set_skill("jiachuan-shu",120);
        //set_skill("houyi-bow",120);
        //set_skill("bow",120);
        //set_skill("liangqing-xiangyi",140);
        //set_skill("moonlight-sword",100);
        set_skill("sword",120);
        set_skill("bibo-sword",100);
        set_skill("perception",100);
        set_skill("xian-steps",120);
	set_skill("canhe-zhi",120);

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
        if(ob->query("gender") == "男性")
        {
                command("say 妾身不收男弟子，去问问我的师哥们吧。");
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

string ask_kao(object me)
{
	object ob;

	if(!me || (me->query("class") != "jinghai"))
		return 0;

	if(me->query("quest/jinghai_quest/quest") != "抓捕")
		return "没事不好好练功，要那东西作什么！";

	ob = new(__DIR__"obj/kao");
	if(!ob)
		return 0;

	ob->move(this_object());

	command(sprintf("give liao kao to %s",me->query("id")));
	return "这些人都是穷凶极恶之徒，要小心行事。";
}
