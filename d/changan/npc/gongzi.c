// gongzi.c

inherit NPC;

void create()
{
	set_name("风流公子", ({ "gong zi" }) );
	set("gender", "男性" );
	set("age", 28);

	set("long", "这是一位风流倜傥的年轻公子，看它的
气度和装束定是从小就娇生惯养。\n");

	set("combat_exp", 1000);
	set("per",35);
	set("str", 20);
	set("force", 200);
	set("max_force", 200);
	set("force_factor", 2);
	setup();

	carry_object(__DIR__"obj/f_fan");
	carry_object(ARMOR_DIR"cloth")->wear();
}