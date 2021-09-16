// genban.c

inherit NPC;

void create()
{
	set_name("跟班", ({ "servant" }) );
	set("gender", "男性" );
	set("age", 28);

	set("long", "这是一位一副奴才像的跟班，不过看起来还有一点功夫。\n");

	set("combat_exp", 2500);
	set("per",20);
	set("str", 25);
	set("force", 200);
	set("max_force", 200);
	set("force_factor", 2);
	set_skill("unarmed",20);

	setup();

	carry_object(ARMOR_DIR"cloth")->wear();
}