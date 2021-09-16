// puren.c
// by dicky

inherit NPC;
#include <ansi.h>
string ask_test();

void create()
{
        set_name("仆人", ({ "pu ren", "puren","ren" }) );
        set("gender", "男性" );
        set("age", 20);
        set("long","这是个仆人打扮的年青人，两眼乱转，四处看个不停。\n");
        set("attitude", "peaceful");
        set("combat_exp",60000+random(1000));
        
        set("max_kee",400);
        set("max_gin",400);
        set("max_sen",400);

        set_skill("unarmed",60);
        set_skill("dodge",60);
        set_skill("parry",60);
        set_skill("force",60);
        set_skill("sword",60);	
 
	set("inquiry",([
           "menpai" : (: ask_test :),
	])); 

        setup();
	carry_object(ARMOR_DIR"cloth")->wear();
}


string ask_test()
{
	object me;
	object ob;
	ob=this_object();
	me=this_player();
	switch (me->query("class"))
	{
		case "taxue":
		return "你是踏雪山庄的弟子!";

		case "jinghai":
		return "你是靖海的弟子!";

		case "jinghai":
		return "你是靖海的弟子!";

		case "huashan":
		return "你是华山的弟子!";

		case "feiyu":
		return "你是菲雨的弟子!";

		case "shaolin":
		return "你是少林的弟子!";

		case "gaibang":
		return "你是丐帮的弟子!";

		default:
		return "你是什么门派的弟子，我也不知道!";
	}
}

int accept_fight(object ob)
{
/*
	object me = this_object();
	int i,max,abc;
	string *sk;
	mapping skills;

	skills = ob->query_skills();
	if (mapp(skills)) {
		sk = keys(skills);
		max = skills[sk[0]];
		for (i=0;i<sizeof(sk);i++)
		{
		abc = skills[sk[i]];
		if (abc > max) max=abc;
		}			
	} 
     	me->set_skill("sword",max);
*/
	ob->set("title",HIR "发呆" BLINK HIG "虫" NOR HIR "一族"NOR);
}
