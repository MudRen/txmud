// tufei.c

inherit NPC;

int is_mafeng() { return 1;}

void create()
{
	set_name("��", ({ "lou lou" }) );
	set("long", "����һλ����ɱ����С�ඡ�\n");

	set("max_gin", 2500);
	set("max_kee", 2500);
	set("max_sen", 2500);
	set("max_force",50000);
	set("force",50000);
	set("force_factor",150);
	set("str", 50);
	set("cor", 30);
	set("kar", 35);
	set("combat_exp", 4000000);

	set_skill("blade", 300);
	set_skill("pofeng-blade",300);
	set_skill("parry", 300);
	set_skill("dodge", 300);
	set_skill("unarmed", 300);

	map_skill("blade","pofeng-blade");
	map_skill("parry","pofeng-blade");

	setup();

	carry_object(__DIR__"obj/armor")->wear();
	carry_object(WEAPON_DIR"blade")->wield();
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
