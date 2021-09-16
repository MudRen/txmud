// yetu.c

inherit NPC;

void create()
{
	set_name("野兔", ({ "ye tu" }) );
	set("race", "野兽");
	set("age", 3);
	set("max_kee", 700);
	set("long", "一只灰色的野兔正用红眼睛看着你。\n");

	set("chat_chance",5);
	set("chat_msg",({
	(: random_move :),
}));
	set("limbs", ({ "头部", "身体", "爪子", "尾巴" }) );
	set("verbs", ({ "bite" }) );

	set("combat_exp", 5000);

	setup();
}
