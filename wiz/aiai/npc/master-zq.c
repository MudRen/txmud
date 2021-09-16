// huashan master-zq.c

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

string ask_me(object who);

void create()
{
	set_name("竹青", ({ "master zhu qing" }) );

	set("nickname", HIG"落雁剑"NOR);

	set("class","huashan");
	set("gender", "女性" );
	set("age", 18);
	set("str", 45);
	set("cor", 30);
	set("int", 60);
	set("per", 30);
	set("con", 30);
	set("kar", 50);

	set("max_gin",5000);
	set("max_kee",5000);
	set("max_sen",5000);

	set("max_force", 5000);
	set("force", 5000);
	set("force_factor", 100);

	set("long",@LONG
竹青出生自武林世家，幼年时家境败落。父母
把他送入华山学艺后便绝迹江湖了。至今一十
五年渺无音信，说来令人伤悲。
LONG );

	create_family("华山派", 4, "小师妹");
	set("combat_exp", 800000);

	set("chat_chance", 1);
	set("chat_msg", ({
		"竹青呤道：胭脂泪，相留醉，几时重。自是人生长恨水长东。\n",
		"竹青呤道：林花谢了春红，太匆匆，无奈朝来寒雨晚来风。。\n",
		"竹青说：也不知这是谁写的，真是好。\n"
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
		"掌门" : (: ask_me :),
]) );

	setup();
	carry_object(__DIR__"obj/green-skirt")->wear();
	carry_object(__DIR__"obj/green-belt")->wear();
}

void attempt_apprentice(object ob)
{
	if(ob->query("gender") != "女性")
	{
		command("say 你去找大师兄问问吧。");
		return;
	}

        if(ob->query("int") < 25) 
	{
		command("say 我派武功需要极好的悟性，否则难有所成。\n" +
		RANK_D->query_respect(ob) + "的悟性好像，咳...，不如你干点别的吧！");
		return;
	}

	command("shy");
	command("say 好吧，我先教你吧，你多加努力，等师傅回来你可以问问他收不收你。\n");
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
