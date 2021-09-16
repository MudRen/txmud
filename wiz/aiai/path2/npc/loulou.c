// loulou.c

inherit NPC;

object my_weapon;

void create()
{
	set_name("小喽喽", ({ "lou lou" }) );
        set("gender", "男性");
        set("age", 27);
        set("long", "这是一位流利流气年轻人。\n");

	//set("no_exp_gain",1);
	set("cor",50);
        set("combat_exp", 300000);

        set("attitude", "killer");

	set("max_kee",800);
	set("max_gin",600);
	set("max_sen",600);

        set_skill("blade", 200);
	set_skill("unarmed", 200);
        set_skill("parry", 200);
        set_skill("dodge", 200);

        setup();
	carry_object(ARMOR_DIR"cloth")->wear();

	if(my_weapon = carry_object(WEAPON_DIR"blade"))
		my_weapon->wield();
}

void die()
{
	if(my_weapon)
		destruct(my_weapon);
	::die();
}
