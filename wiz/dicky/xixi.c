// puren.c
// by dicky

inherit NPC;
#include <ansi.h>
string ask_test();

void create()
{
        set_name("����", ({ "pu ren", "puren","ren" }) );
        set("gender", "����" );
        set("age", 20);
        set("long","���Ǹ����˴��������ˣ�������ת���Ĵ�������ͣ��\n");
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
		return "����̤ѩɽׯ�ĵ���!";

		case "jinghai":
		return "���Ǿ����ĵ���!";

		case "jinghai":
		return "���Ǿ����ĵ���!";

		case "huashan":
		return "���ǻ�ɽ�ĵ���!";

		case "feiyu":
		return "���Ƿ���ĵ���!";

		case "shaolin":
		return "�������ֵĵ���!";

		case "gaibang":
		return "����ؤ��ĵ���!";

		default:
		return "����ʲô���ɵĵ��ӣ���Ҳ��֪��!";
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
	ob->set("title",HIR "����" BLINK HIG "��" NOR HIR "һ��"NOR);
}
