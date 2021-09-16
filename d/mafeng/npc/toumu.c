// toumu.c

inherit NPC;

int is_mafeng() { return 1;}

void create()
{
	set_name("��һ��", ({ "ma yigun" }) );
	set("title","���ɽ��ү");
	set("long", "����һλ�⺷�������ˡ�\n");
	set("age", 45);

	set_auto_recover(1);

	set("chat_chance_combat",15);
	set("chat_msg_combat",({
	(: perform_action, "fork.heng" :),
}));

	set("max_gin", 4500);
	set("max_kee", 4500);
	set("max_sen", 4500);
	set("max_force",50000);
	set("force",50000);
	set("force_factor",150);
	set("str", 100);
	set("cor", 30);
	set("kar", 35);
	set("combat_exp", 5000000);

	set_skill("fork", 300);
	set_skill("qiuyue-fork",300);
	set_skill("parry", 320);
	set_skill("dodge", 320);
	set_skill("unarmed", 300);

	map_skill("fork","qiuyue-fork");
	map_skill("parry","qiuyue-fork");

	setup();

	carry_object(__DIR__"obj/armor")->wear();
	carry_object(WEAPON_DIR"spear")->wield();
}

void init()
{
	object who = this_player();
	if(who && userp(who))
	{
		set_leader(who);
		kill_ob(who);
		who->kill_ob(this_object());
	}
}
