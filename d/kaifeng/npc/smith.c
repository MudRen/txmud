// smith.c

inherit SMITH;

void create()
{
	set_name("ÁõÍº×Ó", ({ "liu tu zi" }) );
	set("gender", "ÄĞĞÔ" );
	set("title","Ìú½³");
	set("age", 48);
	set("str",88);
	set("long", "¿ª·âÌúÆ÷ÆÌÀÏ°å¡£\n");
	set("combat_exp", 300);
	set("attitude", "friendly");
	set_skill("dodge", 60);
	set_skill("unarmed", 60);

	set_weapon_ability(({"stick", "blade", "whip","staff"}));
	set_ability_level(10);

	setup();

	carry_object(ARMOR_DIR+"cloth")->wear();
}
