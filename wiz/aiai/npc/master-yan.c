// huashan master-lh.c

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

string ask_me(object who);
string ask_feng(object who);

void create()
{
	set_name("令狐冲", ({ "master linghu", "master"}) );

	set("nickname", HIG"平常剑"NOR);

	set("class","huashan");
	set("gender", "男性" );
	set("age", 28);
	set("str", 50);
	set("cor", 30);
	set("int", 60);
	set("per", 30);
	set("con", 30);
	set("kar", 50);

	set("max_force", 5000);
	set("force", 5000);
	set("force_factor", 120);

	set("max_gin",3000);
	set("max_kee",3000);
	set("max_sen",3000);

	set("long",@LONG
令狐冲是掌门岳不群从小收留的孤儿，年纪
虽不太大，拜入师门却是最早，是华山派的
大弟子。只因他秉性不羁，又喜杯中物。所
以虽得岳不群亲传了紫霞神功，武功却也不
是武林中出类拔粹的高手。
LONG );

	create_family("华山派", 4, "大师兄");
	set("combat_exp", 1000000);
	set("score", 300000);

	set("chat_chance", 1);
	set("chat_msg", ({
	"咳，也不知师傅的紫霞神功修习得如何了。\n",
	"咳，自从管理本派琐事，我都三个月没喝一滴酒了。\n",
	"对酒当歌，人生几何。\n",
}) );

	set("chat_chance_combat", 60);
	set("chat_msg_combat", ({
		(: exert_function, "recover" :),
}) );

	set_skill("unarmed", 160);
	set_skill("parry", 160);
	set_skill("dodge", 160);
	set_skill("sword", 180);
	set_skill("force", 180);
	set_skill("huashan-sword", 180);
	set_skill("literate", 160);
	set_skill("zixia-force", 180);
	set_skill("lingyun-steps", 160);
	set_skill("fuyunshou", 160);

	map_skill("unarmed", "fuyunshou");
	map_skill("sword", "huashan-sword");
	map_skill("force", "zixia-force");
	map_skill("dodge", "lingyun-steps");

	set("inquiry", ([
		"华山派" : "华山派门户暂时由我代掌，你有何指教？",
		"拜师"   : "华山派以内功和剑法闻名，收弟子最重悟性。",
		"apprentice": "华山派以内功和剑法闻名，收弟子最重悟性。",
		"name": "我便是华山派的令狐冲，现在代掌华山派。",
		"掌门" : (: ask_me :),
		"风清杨" : (: ask_feng :),
]) );

	setup();
	// carry_object(__DIR__"obj/cloth")->wear();
}
   
void attempt_apprentice(object ob)
{
	if(ob->query("gender") != "男性")
	{ command("say 你去找小师妹去吧。"); return; }

        if(ob->query("int") < 25)
	{
		command("say 我派武功需要极好的悟性，否则难有所成。\n" +
		RANK_D->query_respect(ob) + "的悟性好像，咳...，不如你干点别的吧！");
		return;
	}

	command("smile");
	command("say 很好，" + RANK_D->query_respect(ob) + 
"多加努力，他日必定有成。\n");
	command("recruit " + ob->query("id") );
}

void recruit_apprentice(object ob)
{
	if( ::recruit_apprentice(ob) )
		ob->set("class", "huashan");
}

string ask_me(object who)
{
	if(!who->is_apprentice_of(this_object()))
		return 0;

	if( (who->query_skill("dodge",1) < 160)
	|| (who->query_skill("zixia-force",1) < 160) )
		return "我派武功循序渐进，先打好基础再说。";

	return "师傅在瀑布附近的凌微洞闭关精研紫霞秘籍，只有每日\n\t午间打坐休息，你可那时去拜见讨教。";
}

string ask_feng(object who)
{
	if(who->query("class") != "huashan")
		return 0;

	if(who->query_temp("asked_lh_about_feng"))
		return "不是和你说过了，不好好练功总是问这问那做什么。";

	if( (who->query_skill("dodge",1) < 160)
	|| (who->query_skill("zixia-force",1) < 160) )
		return "那是我派的前辈高人，听说早已隐居不出了。";

	who->set_temp("asked_lh_about_feng",1);
	return "那是我派的前辈高人，早已隐居不出了，他老人家的隐居之所\n
谁也不知道，不过有传言他老人家就隐居在华山。咱们紫霞宫
住的那个小女孩，虽说不是我华山派门徒，但据说和我派大有
渊源，她从小就在华山四处游荡，你可以去向她打听打听。";
}
