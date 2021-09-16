// wujiang.c

inherit NPC;

void create()
{
	set_name("武将", ({ "wu jiang" }) );
	set("gender", "男性" );
	set("age", 35);

	set("max_kee",900);
	set("max_gin",900);
	set("max_sen",1000);
	set("max_force",1000);
	set("force",1000);
	set("force_factor",20);

	set("combat_exp", 500000);

	set("long", "这是一位武将，黝黑的脸上露着英武之气。\n");

	set_skill("blade",90);
	set_skill("parry",100);
	set_skill("dodge",120);
	set_skill("unarmed",100);

	setup();

	carry_object(ARMOR_DIR"armor")->wear();
	carry_object(WEAPON_DIR"blade")->wield();
}
