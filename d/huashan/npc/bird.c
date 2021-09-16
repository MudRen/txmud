inherit NPC;

void create()
{
	set_name("山雀", ({ "shan que" }) );
        set("race", "野兽");
        set("age", 1);

        set("gender", "雌性");
        set("long", "一只美丽的小山雀，唧唧喳喳叫个不停! \n");

	set("str", 20);

	set("combat_exp", 1000);
        set("attitude","peaceful");

	set("limbs", ({ "头部", "身体","翅膀" }) );
	set("verbs", ({ "bite","claw" }) );

	set_temp("apply/dodge", 100);

	set("chat_chance", 2);
	set("chat_msg", ({
		(: random_move :),
		"山雀用嘴整理羽毛。 \n",
		"山雀见到有人就展开翅膀飞了。 \n",
	}) );

        setup();
}
/*

void die()
{
	object ob;
	message_vision("$N凄惨的嚎了几声，死了。\n", this_object());
	ob = new(__DIR__"obj/shanjirou");
	ob->move(environment());
	destruct(this_object());
} */

