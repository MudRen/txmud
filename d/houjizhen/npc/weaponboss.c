// weaponboss.c
// by dicky

inherit F_DEALER;

void create()
{
	set_name("兵器铺老板", ({ "weapon boss", "boss" }) );
	set("gender", "男性" );
	set("age", 40);
	set("long", "兵器铺老板个脸上有一道伤疤中年人，一笑起来份外诡异。\n");
	set("combat_exp", 30000);
	set("attitude", "friendly");
	set("max_kee",1000);
	set("max_force",1000);
	set("force_factor",40);
	set_skill("unarmed", 100);
	set_skill("dodge", 100);
	set_skill("sword", 100);
	set_skill("parry", 120);
	set(NO_KILL,1);
	set("sell_all_day",1);
	set("inquiry", ([
		"兵器" : "本店专卖各种长短兵器", 
	]) );

	set("vendor_goods", ([
		WEAPON_DIR"sword" : 10,
		WEAPON_DIR"whip": 10,
		WEAPON_DIR"dart": 100,
                WEAPON_DIR"spear":10,
		WEAPON_DIR"sixhammer":10,
		WEAPON_DIR"thin_sword":10,
		WEAPON_DIR"dagger":10,
		WEAPON_DIR"stick":10,
		WEAPON_DIR"blade":10,
		WEAPON_DIR"staff":10,
	]) );

	setup();
        carry_object(ARMOR_DIR"cloth")->wear();
        carry_object(WEAPON_DIR"sword")->wield();
}