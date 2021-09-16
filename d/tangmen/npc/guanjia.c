// guanjia.c

inherit QUESTER;

void create()
{
	set("class", "tangmen");

	set_name("唐管家", ({"tang guanjia"}));
	set("title", "赏罚分明");

	set("long", @TEXT
唐忠是上一代堡主的仆人，出身微贱，
但却非常聪颖，在老堡主身边耳濡目
睹数十年，对各种毒物研究有加，尤
其擅长解毒。
TEXT
);

	set(NO_KILL, 1);

	set("gender","男性");
	set("age",65);
	set("con",20);
	set("str",20);
	set("combat_exp",200);

	setup();
	carry_object(ARMOR_DIR"cloth")->wear();
}
