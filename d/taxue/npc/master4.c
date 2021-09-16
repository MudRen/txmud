// master4.c
// by dicky

#include <ansi.h>
inherit NPC;
inherit F_MASTER;

// string ask_title();

void create()
{
        set_name("踏雪青云", ({ "taxue qingyun", "master", "qingyun" }) );
        set("class","taxue");
        set("nickname",HIG"雪中飞狐"NOR);
        create_family("踏雪山庄", 2, "弟子");

        set("gender", "男性" );
        set("age", 27);
        set("attitude", "peaceful");
        set("long", "锦衣长袍，面目清秀，一副儒生打扮。
		他就是踏雪山庄掌门大弟子。小时候是个孤儿，
		后来被踏雪山庄庄主夫妇收留，并教其武功。
		他勤学苦练，终于成为武林中数一数二的高手，
		江湖人称他为“雪中飞狐”。\n"
	);

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

        set_skill("taxue-force",180);
        set_skill("fenghui-sword",180);
        set_skill("xueli-steps",180);
        set_skill("chuanyun-zhang",180);
        set_skill("unarmed",180);
        set_skill("literate",150);
        set_skill("dodge",180);
        set_skill("parry",180);
        set_skill("force",180);
        set_skill("sword",180);

        map_skill("force","taxue-force");
        map_skill("sword","fenghui-sword");
        map_skill("dodge","xueli-steps");
        map_skill("unarmed","chuanyun-zhang");
        map_skill("parry","fenghui-sword");	

//	set("inquiry", ([
//		"title": (: ask_title :),
//	]));
	

        setup();
        carry_object(WEAPON_DIR"sword")->wield();
        carry_object(ARMOR_DIR"cloth")->wear();
}

 
void attempt_apprentice(object ob)
{
	string startxx;
	startxx= "/d/taxue/dating";

        if( ob->query("class") == "taxue")
        {
		command("say 见笑了，你已有名师指点，何必再来找我呢？");
		return;
        }

        if( ob->query("title") != "普通百姓")
        {
		command("say 『踏雪山庄』向来不收叛徒，请尽快离开。");
		return;
        }

	if( (ob->query("per") < 25) || (ob->query("age") > 14) )
	{
		command("say 『踏雪山庄』向来只收年轻漂亮的孩子，你还是走吧。");
		return;
	}

                command("smile");
                command("say 不错，" + RANK_D->query_respect(ob) + "多加努力，他日必有所成。\n");
                command("recruit " + ob->query("id") );

                ob->set("startroom",startxx);
                ob->save();
}

int recruit_apprentice(object ob)
{
        ::recruit_apprentice(ob);
        ob->set("class", "taxue");
        return 1;
}

/*
string ask_title()
{
        object ob;
        ob = this_player();

        if(ob->query("class")!="taxue")
		return "哈哈……，你好象不是本门弟子！\n";

	if(ob->query("family/master_id") != "taxue rongbo")
		return "呵呵，你的实在经验这么差，还是去多努力吧！\n";

        if(ob->query("title")!=HIW"残剑飞雪衣钵传人"NOR)
	ob->set("title",HIW"残剑飞雪衣钵传人"NOR);
	return "呵呵，是不是头衔有错误呀？我马上跟你更换过来！\n";
}
*/

