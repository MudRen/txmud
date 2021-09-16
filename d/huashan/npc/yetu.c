// yetu.c 野兔

inherit NPC;

void create()
{
        set_name("野兔", ({ "ye tu" }) );
	set("race", "野兽");

	set("age", 5);
	set("long", "一只好可爱的小野兔。\n");
	set("attitude", "peaceful");
	
	set("limbs", ({ "头部", "身体", "前脚", "后脚", "尾巴" }) );
	set("verbs", ({ "bite", "claw" }) );

	set("combat_exp", 1000);

        set("chat_chance", 2);
        set("chat_msg", ({
                (: random_move :),
		"野兔用前腿捋捋胡子，小心地向四周看看。 \n",
		"野兔低下头吃了几口草，又抬头向四周看看。\n",
		"野兔突然停下来，竖起耳朵机警地注意听着什么。",
        }) );
	
        set_temp("apply/attack", 15);
        set_temp("apply/defense", 25);
        set_temp("apply/damage", 10);
        set_temp("apply/armor", 10);

	setup();
}

void die()
{
	object ob;

	message_vision("$N死了。\n", this_object());

	ob = new(__DIR__"obj/turou");
	ob->move(environment(this_object()));
	destruct(this_object());
}
