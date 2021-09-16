// out_vendor.c

inherit NPC;

void create()
{
	set_name("外地商人", ({ "trader" }) );
	set("gender", "男性" );
	set("age", 46);
	set("long", "这是一位商人模样的人，从装束上看是从外地来的。\n");
	set("per", 25);
	set("combat_exp", 12000);

	set_skill("unarmed", 30);
	set_skill("parry", 50);
	set_skill("dodge",20);

	setup();
	add_money("coin", 10);
	carry_object(ARMOR_DIR"cloth")->wear();
}
