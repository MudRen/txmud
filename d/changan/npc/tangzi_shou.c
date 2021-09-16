// tangzi_shou.c

inherit NPC;
 
void create()
{
	set_name("趟子手", ({"tangzi shou",}));
	set("long", "这位是德威镖局的趟子手。\n");
	set("gender","男性");
	set("title","德威镖局");

	set("chat_chance",5);
	set("chat_msg",({
	"德威镖局，威德远播。\n"
}));
	set("age",38);
	set("con",30);
	set("str",20);
	set("max_kee",700);
	set("max_gin",750);
	set("max_sen",750);

	set_skill("dodge",60);
	set_skill("parry",60);
	set_skill("unarmed",60);
	set_skill("blade",30);

	set("combat_exp",80000);

	setup();
	carry_object(WEAPON_DIR"blade")->wield();
	carry_object(ARMOR_DIR"cloth")->wear();
}