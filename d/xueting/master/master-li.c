// huashan masterli.c
// edit by pian

#include <ansi.h>
inherit NPC;
inherit F_MASTER;

string ask_me(object who);
string ask_feng(object who);

void create()
{
	set_name("李得全", ({ "master li", "master"}) );

	set("nickname", HIG"雪亭分舵舵主"NOR);

	set("class","gaibang");
	set("gender", "男性" );
	set("age", 28);
	set("str", 50);
	set("cor", 30);
	set("int", 60);
	set("per", 30);
	set("con", 30);
	set("kar", 50);

	set("max_force", 1000);
	set("force", 1000);
	set("force_factor", 20);

	set("max_gin",800);
	set("max_kee",800);
	set("max_sen",800);

	set("long",@LONG
丐帮雪亭镇分舵的四袋弟子，想入丐帮找他就对了。
他得了帮主传授的丐帮内功，虽不到家，也还凑合用了。
LONG );

	create_family("丐帮", 8, "四袋弟子");
	set("combat_exp", 100000);
	set("score", 3000);

	set("chat_chance", 1);
	set("chat_msg", ({
	"丐帮可是江湖中第一大帮，这几年英雄辈出、人才济济。\n",
	"莲花开、莲花落、有人富贵有人落魄......\n",
	"呵呵，我也要加紧练功，明年一定要再升一只口袋。\n",
}) );

	set("chat_chance_combat", 60);
	set("chat_msg_combat", ({
		(: exert_function, "recover" :),
}) );

	set_skill("begging",120);
	set_skill("literate",80);
	set_skill("unarmed",120);
	set_skill("parry", 120);
	set_skill("dodge", 120);
	set_skill("stick", 120);
	set_skill("force", 180);
	set_skill("taizu-changquan",120);
	set_skill("taizu-force",180);
	set_skill("gaibang-force",60);
	set_skill("gaibang-steps",120);
	set_skill("taizu-gun", 120);
	
/*	set_skill("huashan-sword", 180);
	set_skill("literate", 160);
	set_skill("zixia-force", 180);
	set_skill("lingyun-steps", 160);
	set_skill("fuyunshou", 160);

	
	map_skill("sword", "huashan-sword");
	map_skill("force", "zixia-force");
*/
	map_skill("unarmed", "taizu-changquan");
	map_skill("stick", "taizu-gun");
	map_skill("dodge","gaibang-steps");
	map_skill("force", "taizu-force");
	set("inquiry", ([
		"丐帮"      : "丐帮？丐帮天下各处都有分舵啊？",
		"拜师"      : "丐帮以内功和棍法闻名，想入丐帮拜我就行了。",
		"apprentice": "丐帮以内功和棍法闻名，想入丐帮拜我就行了。",
		"name"	    : "我便是雪亭镇分舵四袋弟子[李得全]。",
		"帮主"      : "丐帮帮主便是“鲁有角”大虾啊。",
		"洪七公"    : "啊，洪老师祖，我入帮时见过他老人家一面。",
]) );

	setup();
	//carry_object(__DIR__"/obj/wood_stick")->wield();
	carry_object(ARMOR_DIR"cloth")->wear();
}
   
void attempt_apprentice(object ob)
{
//	if(ob->query("gender") != "男性")
//	{ command("say 你去找小师妹去吧。"); return; }

//        if(ob->query("class")="gaibang")
//	{
//		command("say 你没入我派，我怎么收你作二袋弟子啊。\n");
//		return;
//	}
	if( (ob->query_skill("begging",1) < 80)
		|| (ob->query_skill("taizu-force",1) < 80) )
		{
		command("say 我先回去学好[乞讨]和[太祖心法]，否则难有所成。\n");
		return;
	}
	
	command("smile");
	command("say 很好，" + RANK_D->query_respect(ob) + 
"多加努力，他日必定成为一代名丐。\n");
	command("recruit " + ob->query("id") );
}


void recruit_apprentice(object ob)
{
	if( ::recruit_apprentice(ob) )
		ob->set("class", "gaibang");
}

string ask_me(object who)
{
	if(!who->is_apprentice_of(this_object()))
		return 0;

	if( (who->query_skill("dodge",1) < 160)
	|| (who->query_skill("taizu-force",1) < 160) )
		return "我派武功循序渐进，先打好基础再说。";

	return "你先想办法背上九个口袋再去见帮主吧。";
}

string ask_feng(object who)
{
	if(who->query("class") != "gaibang")
		return 0;

	if(who->query_temp("asked_wyq_about_hqg"))
		return "不是和你说过了，不好好练功总是问这问那做什么。";

	if( (who->query_skill("dodge",1) < 160)
	|| (who->query_skill("zixia-force",1) < 160) )
		return "那是我派的前辈高人，听说早已隐居不出了。";

	who->set_temp("asked_wyq_about_hqg",1);
	return "
洪七公是掌门的师傅，他老人家云游四海，游戏风尘，居无定
所。你想找他就难了。不过你可以找帮主问问看。帮主这两天
会去长安城。";
}