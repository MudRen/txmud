// shusheng.c

inherit NPC;

void create()
{
	set_name("文弱书生", ({ "shu sheng" }) );
	set("gender", "男性" );
	set("age", 28);

	set("long", "这是一位年轻的书生。\n");

	set("combat_exp", 1000);

	set("chat_chance", 10);
	set("chat_msg", ({
		(: random_move :)
	}) );

	set("per",20);
	set("str", 20);
	set("max_kee",400);
	setup();

	carry_object(ARMOR_DIR"cloth")->wear();
}