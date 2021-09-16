// cxf_huyuan.c

inherit NPC;

void create()
{
	set_name("护院", ({ "hu yuan"}) );
	set("gender", "男性");
	set("age", 27);

	set("long","这是一位丞相府的护院，只见他一脸凶神恶煞的模样。\n");
	set("combat_exp", 1000000);
	set("str",40);
	set("con",40);
	set("kar",40);

	set("max_force",2000);
	set("force",2000);
	set("force_factor",200);
	set("max_atman",1500);
	set("atman",1500);
	set("max_mana",1500);
	set("mana",1500);
	set("max_kee",2000);
	set("max_gin",2000);
	set("max_sen",2000);
	set("attitude", "heroism");

	set_skill("unarmed",200);
	set_skill("force",200);
	set_skill("blade", 250);
	set_skill("parry", 200);
	set_skill("dodge", 200);
	set_skill("ganchan", 150);
	set_skill("cibei-blade", 250);

	map_skill("dodge","ganchan");
	map_skill("blade","cibei-blade");

	setup();

	carry_object(WEAPON_DIR"blade")->wield();
	carry_object(ARMOR_DIR"cloth")->wear();
}

int heal_up()
{
	if( environment() && living(this_object()) && !is_fighting() )
	{
		call_out("do_leave", 1);
		return 1;
	}
	return ::heal_up() + 1;
}

void do_leave()
{
	string *dirs;
	mapping exits;

	exits = environment()->query("exits");

	if(!sizeof(exits))
		tell_room(environment(),name()+"匆匆忙忙的走了。\n");
	else
	{
		dirs = keys(exits);
		message_vision(sprintf("$N往%s离开。\n",
			to_chinese(dirs[random(sizeof(dirs))]) ),this_object());
	}
	destruct(this_object());
}