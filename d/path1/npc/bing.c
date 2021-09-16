// bing.c

inherit NPC;

void create()
{
	set_name("����", ({ "bing ding" }) );
	set("gender", "����" );
	set("age", 25);

	set("max_kee",900);
	set("max_gin",1000);
	set("max_sen",1000);
	set("max_force",1000);
	set("force",1000);
	set("force_factor",10);

	set("combat_exp", 250000);

	set("long","���Ǳ߹ص�һ���������������վ�š�\n");

	set_skill("fork",80);
	set_skill("parry",100);
	set_skill("dodge",100);
	set_skill("unarmed",80);

	setup();

	carry_object(ARMOR_DIR"armor")->wear();
	carry_object(WEAPON_DIR"spear")->wield();
}
