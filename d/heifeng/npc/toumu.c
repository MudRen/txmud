// toumu.c

inherit NPC;

void create()
{
	int n = random(2);
	set_name("小头目", ({ "tou mu" }) );

	set("title","黑风寨");
	set("gender", "男性");
	set("age", 33);
	set("long", "这家伙满脸横肉，一付凶神恶煞的模样，令人望而生畏。\n");
	set("combat_exp", 2000000);

	set("vendetta_mark", "heifeng_tufei");

	set("max_kee",1500);
	set("max_gin",1500);
	set("max_sen",1500);
	set("max_force",1500);
	set("force",1500);
	set("force_factor",40);

	set("chat_chance", 15);
	set("chat_msg", ({
		(: random_move :)
	}) );

	set("bellicosity", 600);
	set("attitude", "heroism");
	set_skill("unarmed", 150);
	if(n)
		set_skill("fork", 150);
	else
		set_skill("blade", 150);
	set_skill("parry", 150);
	set_skill("dodge", 150);
	set_skill("ganchan",70);

	map_skill("dodge","ganchan");

	setup();
	if(n)
		carry_object(__DIR__"obj/spear")->wield();
	else
		carry_object(__DIR__"obj/blade")->wield();
	carry_object(ARMOR_DIR"cloth")->wear();
}
