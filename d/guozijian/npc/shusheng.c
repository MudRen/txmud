// shusheng.c
inherit NPC;

void create()
{
	set_name("书生", ({ "student" }) );
	set("long",
		"一个身穿白缎长袍的书生。\n");
	set("age", 25);
	set("attitude", "friendly");
	set("combat_exp", 10);
	set("chat_msg_combat", ({
		"书生叫道：杀人哪！救命哪！\n",
	}) );
	setup();
	carry_object(ARMOR_DIR"cloth")->wear();
	add_money("coin", 20);
}
