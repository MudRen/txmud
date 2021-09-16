// xiazi.c
// by dicky

#include <ansi.h>
inherit NPC;

void create()
{
	set_name("�����", ({ "e heshang","heshang"}) );
	set_auto_recover(1);
	set("gender", "����" );
	set("age", 40);
	set("long", "���������ɷ�ĺ��У�������һ���˰̣�������һֱ���쵽��͵���ߡ�\n");

	set("combat_exp", 100000);
	set("str", 30);
	set("max_kee",2000);
	set("kee",2000);
	set("max_gin",2000);
	set("gin",2000);
	set("max_sen",2000);
	set("sen",2000);
	set("force", 2000);
	set("max_force", 2000);
	set("mana", 2000);
	set("max_mana", 2000);
	set("force_factor", 30);
	set("chat_chance_combat",20);
	set("chat_msg_combat",({
		(: perform_action, "stick.xiangmo" :),
	}));

	set_skill("unarmed",100);
	set_skill("dodge",100);
	set_skill("parry",100);
	set_skill("force",100);
	set_skill("stick",100);
	set_skill("iron-cloth",100);
	set_skill("perception",100);
	set_skill("yiqi-force",100);
	set_skill("ganchan",100);
	set_skill("luohan-quan",100);
	set_skill("weituo-gun",100);

	map_skill("force","yiqi-force");
	map_skill("dodge","ganchan");
	map_skill("unarmed","luohan-quan");
	map_skill("stick","weituo-gun");
	setup();
	carry_object(WEAPON_DIR"stick")->wield();
	carry_object(__DIR__"obj/jiasha")->wear();
}


void init()
{
	object ob = this_player();
	
	::init();

	if (interactive(ob))
	{
		command("say �󵨿�ͽ�������ƻ�����ү�ĺ���������\n\n");
		command("say ������·�㲻�ߣ�����������ƫ��������\n\n");
		remove_call_out("kill_ob");
		call_out("kill_ob", 1, ob); 
		ob->delete_temp("ganjiang/heshang",1);
	}       
}
