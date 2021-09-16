// huashan master-feng.c

#include <ansi.h>

inherit NPC;
inherit F_MASTER;
inherit F_DTIME;

string ask_me(object who);

void create()
{
	set_name("风清杨", ({ "master feng"}) );
	set("nickname",WHT"独孤剑圣"NOR);
	set("gender", "男性" );
	set("class", "huashan");

	set("age", 84);
	set("str", 80);
	set("cor", 30);
	set("int", 60);
	set("per", 30);
	set("con", 60);
	set("kar", 60);

	set("max_force", 20000);
	set("force", 20000);
	set("force_factor", 400);

	set_disappear_msg("\n你只觉得眼前一闪，定睛一看，风清杨已经不见了。\n");
	set_appear_time(([
	",,1380":",,300",
]));

	set("max_gin",10000);
	set("max_kee",10000);
	set("max_sen",10000);

	set("long",@LONG
风清杨是岳不群的师叔，一生醉心于剑术。对
于功名利禄却不在意。因与岳不群的师父不和，
便云游四海以剑会友，倒遂了素愿。
LONG );

	create_family("华山派", 2, "师叔");

	set("combat_exp", 7000000);

	set_skill("unarmed", 250);
	set_skill("parry", 300);
	set_skill("dodge", 300);
	set_skill("literate", 300);
	set_skill("sword", 300);
	set_skill("dugu-sword",300);
	set_skill("force", 300);
	set_skill("lingyun-steps",300);
	set_skill("fuyunshou", 250);
	set_skill("zixia-force",250);

	map_skill("unarmed", "fuyunshou");
	map_skill("sword", "dugu-sword");
	map_skill("dodge", "lingyun-steps");

	set("inquiry", ([
]) );

	setup();
    //carry_object(__DIR__"obj/cloth")->wear();
    //carry_object(WEAPON_DIR"bamboo_sword")->wield();
}

void attempt_apprentice(object ob)
{
	if(ob->query("class") != "huashan")
		return;

	if(ob->query_skill("huashan-sword",1))
	{
		command("say 既然是深研华山剑法的气宗弟子，去找岳不群等着“以气御剑”吧。");
		command("heng");
		return;
	}

	if(ob->query("int") < 31)
	{
		command("say 独孤剑法以无招胜有招，重“悟”不重“学”，你的悟性差的太远了。");
		command("shake");
		return;
	}

	command("smile");
	command("say 很好，" + RANK_D->query_respect(ob) + 
		"多加努力，他日必定有成。\n");

	command("recruit " + ob->query("id") );
	ob->save();
}

void recruit_apprentice(object ob)
{
	if( ::recruit_apprentice(ob) )
		ob->set("class", "huashan");
}

int prevent_learn(object who,string skill)
{
	int n;

	if(who->query_skill("huashan-sword",1))
		return notify_fail("既然是深研华山剑法的气宗弟子，去找岳不群等着“以气御剑”吧。\n");

	n = query_time();
	if((n < 1380) && (n > 300))
		return notify_fail("白天我要出去走走，你晚上再来吧。\n");
	return 1;
}
