// GaiBang master-Q.c

#include <ansi.h>
inherit QUESTER;

string ask_me(object who);

void create()
{
	set_name("痴丐", ({ "master chi", "master"}) );
	//set("nickname", HIG""NOR);
	set("gender", "男性" );
	set("class","gaibang");

	set("age", 54);
	set("str", 65);
	set("cor", 30);
	set("int", 60);
	set("per", 30);
	set("con", 40);
	set("kar", 50);

	set("max_force", 4000);
	set("force", 4000);
	set("force_factor", 300);

	set("max_gin",5000);
	set("max_kee",5000);
	set("max_sen",5000);

	set("long",@LONG
一个疯疯痴痴的老乞丐。
LONG );

	create_family("丐帮", 3, "八袋长老");
	set("combat_exp", 3000000);
       
	set_skill("unarmed", 250);
	set_skill("parry", 250);
	set_skill("dodge", 250);
	set_skill("sword", 250);
	set_skill("force", 260);
//	set_skill("huashan-sword", 250);
//	set_skill("literate", 300);
//	set_skill("zixia-force", 260);
//	set_skill("lingyun-steps", 250);
//	set_skill("fuyunshou", 250);

//	map_skill("unarmed", "fuyunshou");
//	map_skill("sword", "huashan-sword");
//	map_skill("force", "zixia-force");
//	map_skill("dodge", "lingyun-steps");

	set("inquiry", ([
		"丐帮":"天下无处不是丐帮啊。",
//		"华山派" : "这里就是华山派。",
//		"拜师"   : (: ask_me :),
//		"apprentice": (: ask_me :),
//		"name": "哦，你连我都不认得？",
//		"岳不群":"是我相公，他就是华山掌门了。",
//		"here": "这里便是华山。",
]) );

	setup();
	//carry_object(__DIR__"obj/erhuangao")->wear();
	//carry_object(__DIR__"obj/sword")->wield();
}

string ask_me(object who)
{
	if(who->query("gender") == "男性")
		return "你去找梅又权吧，我不收徒弟。";
	else
		return "你去找梅又权吧，我不收徒弟。";
}
