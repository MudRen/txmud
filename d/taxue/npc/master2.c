// master2.c
// by dicky

#include <ansi.h>
inherit NPC;
inherit F_MASTER;

string ask_mimi();

void create()
{
	set_name("踏雪靖远", ({ "taxue jingyuan","jingyuan","master"}) );
        set("class","taxue");
        create_family("踏雪山庄", 1, "弟子");
        set("title",HIW"风掌雪剑"NOR);	
	set("nickname",HIY"踏雪山庄庄主"NOR);

	set("age", 53);
	set("long", "锦衣长袍，面目清秀，一副儒生打扮。他就是踏雪山庄庄主。\n");
	set("attitude","heroism");
	set("gender", "男性" );

        set("combat_exp", 4000000);
        set("str", 80);
        set("per", 30);
        set("max_kee",4000);
        set("kee",4000);
        set("max_gin",4000);
        set("gin",4000);
        set("max_sen",4000);
        set("sen",4000);
        set("force", 4000);
        set("max_force", 4000);
        set("atman", 4000);
        set("max_atman", 4000);
        set("mana", 4000);
        set("max_mana", 4000);
        set("force_factor", 200);
	set("chat_chance_combat",40);
	set("chat_msg_combat",({
		(: perform_action, "sword.qicai" :),
	}));

       set("inquiry", ([
                "秘密" : (: ask_mimi :),
                 "mimi" : (: ask_mimi :),
       ]));

        set_skill("taxue-force",250);
        set_skill("fenghui-sword",250);
        set_skill("xueli-steps",250);
        set_skill("chuanyun-zhang",250);
        set_skill("unarmed",250);
        set_skill("literate",200);
//        set_skill("zhouyi",200);
        set_skill("dodge",250);
        set_skill("parry",250);
        set_skill("force",250);
        set_skill("sword",250);

        map_skill("force","taxue-force");
        map_skill("sword","fenghui-sword");
        map_skill("dodge","xueli-steps");
        map_skill("unarmed","chuanyun-zhang");
        map_skill("parry","fenghui-sword");	

        setup();
        carry_object(WEAPON_DIR"sword")->wield();
        carry_object(__DIR__"obj/jinduan")->wear();

}


void attempt_apprentice(object ob)
{
	if(ob->query("class") != "taxue")
		return;

	if(ob->query_skill("taxue-force",1) < 180)
	{
		command("say 你的踏雪神功火候不够，回去练练再说吧。");
		return;
        }

	if(ob->query_skill("fenghui-sword",1) < 180)
	{
		command("say 你的风回雪舞剑学得火候不够，回去练练再说吧。");
		return;
        }

	if(ob->query_skill("dodge",1) < 180)
	{
		command("say 你的基本轻功练习得火候不够，回去练练再说吧。");
		return;
        }

	if(ob->query("family/master_id") == "taxue rongbo")
	{
		command("say 见笑了，你已有名师指点，何必再来找我呢？");
		return;
        }

	command("smile");
	command("say 很好，" + RANK_D->query_respect(ob) + "多加努力，他日必有所成。\n");
	command("recruit " + ob->query("id") );
}

int recruit_apprentice(object ob)
{
        ::recruit_apprentice(ob);
        ob->set("class", "taxue");
        return 1;
}

string ask_mimi()
{
        object ob;
        ob = this_player();

        if(ob->query("class")!="taxue")
        return "对不起，"+ob->name()+"，我没有什么秘密好告诉你！";

        if(ob->query_temp("taxue/ask_master"))
        return "你刚才不是问过了么，怎么又来了？";

	ob->set_temp("taxue/ask_master",1);
        return ""+ob->name()+"，在后山的山谷中住着本门的一位前辈，如果能得到他的指点，你就是三生有幸！";
}
