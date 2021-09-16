// xiangke.c

inherit NPC;

void create()
{
	set_name("进香客", ({ "xiang ke" }) );
	set("gender", "男性" );
	set("age", 25+random(15));
	set("long","这是一位游山玩水的游客，正在欣喜
的四处张望。\n");
	set("combat_exp", 10000+random(5000));
	set("attitude","peaceful");

	set_skill("dodge",40);
	set_skill("unarmed",40);

	setup();
	carry_object(ARMOR_DIR"cloth")->wear();
}