// huashan master-yue.c
// 11:00 - 15:00 学习时间

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

string ask_ziqi(object who);

void create()
{
	set_name("岳不群", ({ "master yue" }) );
	set("nickname",HIW"华山掌门"NOR);

	set("class","huashan");

	set("gender", "中性" );

	set("age", 54);
	set("str", 80);
	set("cor", 30);
	set("int", 60);
	set("per", 30);
	set("con", 60);
	set("kar", 50);

	set("max_force", 20000);
	set("force", 20000);
	set("force_factor", 400);

	set("max_gin",10000);
	set("max_kee",10000);
	set("max_sen",10000);

	set("long",@LONG
岳不群就是现任的华山掌门，精明能干，天份
极高。为人作事极有心计。娶了掌门的女儿，
对他当上华山掌门也是极有好处。他为华山的
壮大发展倒是不遗余力。
LONG );

	create_family("华山派", 3, "掌门");
	set("combat_exp", 7000000);

	set_skill("unarmed", 280);
	set_skill("parry", 280);
	set_skill("dodge", 280);
	set_skill("sword", 300);
	set_skill("force", 300);
	set_skill("huashan-sword", 300);
	set_skill("literate", 300);
	set_skill("zixia-force", 300);
	set_skill("lingyun-steps", 280);
	set_skill("fuyunshou", 280);

	map_skill("unarmed", "fuyunshou");
	map_skill("sword", "huashan-sword");
	map_skill("force", "zixia-force");
	map_skill("dodge", "lingyun-steps");

	set("inquiry", ([
		"ziqi": (: ask_ziqi :),
		"紫气东来": (: ask_ziqi :),
]) );

	setup();
	carry_object(__DIR__"obj/hs_cloth")->wear();
}
       
void attempt_apprentice(object ob)
{
	if(ob->query("class") != "huashan")
		return;

	if( ob->query("int") < 30 )
	{
		command("say 修习我派心法不但需要持之以恒的毅力，更需要极好的悟性！");
		return;
	}

	if( ob->query_skill("dugu-sword",1) )
	{
		command("say 既然学得了风师叔的「独孤九剑」，我这点雕虫小技不学也罢。");
		command("heng");
		return;
	}

	if( ob->query_skill("zixia-force",1) < 160 )
	{
		command("say 你的紫霞神功火候太差，不宜进修。。。");
		return;
	}

	command("smile");
	command("say 很好，虽叫「华山剑派」，外人却不知我派内功才真是博大精深，\n            以气御剑才是我派武功精髓。望你勤学苦练，日后光大我派门楣。\n");
	command("recruit " + ob->query("id") );
	ob->save();
	command("say 以后每日「午间」均可来请教武功，其他时间为师要修炼紫霞心法，\n\t以期我派内功能更上一层楼。");
}
    
void recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
        ob->set("class", "huashan");
}

int prevent_learn(object who,string skill)
{
	int n = query_time();

	if( (n < 660) || (n > 900) )
		return notify_fail("岳不群说道：想要请教武功就「午间」来，其他的时候不要来打扰我！\n");

	if(who->query_skill("dugu-sword",1))
		return notify_fail("say 既然学得了风师叔的「独孤九剑」，我这点雕虫小技不学也罢。");

	return 1;
}

string ask_ziqi(object who)
{
	if(!who->is_apprentice_of(this_object()))
		return 0;

	if(who->query("family/master_yue_teach"))
		return "不断修习『紫霞神功』，『紫气东来』的效力会越来越高的。";

	if(who->query_skill("zixia-force",1) < 150)
		return "你的『紫霞神功』功力不够，无法修习『紫气东来』。";

	message_vision("\n$N点了点头，付在$n耳边念了一段什么。。。。。。\n$n面露喜色说道：是。。。弟子晓得了，多谢师傅！\n\n",this_object(),who);
	who->set("family/master_yue_teach",1);
	return "此招可提升『华山剑法』的效力！以后要勤学苦练『紫霞神功』，\n效力会不断提高。。。";
}

