// hockboss.c

inherit NPC;

void create()
{
	set_name(" 常有财", ({ "chang youcai" }) );
	set("gender", "男性" );
	set("age", 50);

	set("long", "这是杭州常记当铺的老板。\n");

	set("combat_exp", 100);
	set("attitude", "friendly");
	set("max_kee",1000);
	set("max_force",1000);
	set("force_factor",20);

	set_skill("unarmed", 100);
	set_skill("dodge", 100);
	set_skill("sword", 100);
	set_skill("parry", 120);

	setup();
        carry_object(ARMOR_DIR"cloth")->wear();
}
