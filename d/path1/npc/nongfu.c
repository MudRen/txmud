// nongfu.c

inherit NPC;

void create()
{
	set_name("农夫", ({ "nong fu" }) );
	set("gender", "男性" );
	set("age", 40 + random(10));
	set("combat_exp", 10000);

	set("long", "这是一位满脸黝黑的农夫。\n");
	set_skill("unarmed",20);

	setup();

	carry_object(ARMOR_DIR"cloth")->wear();
}
