// dizhu_wang.c

inherit NPC;
 
void create()
{
	set_name("王千顷", ({ "wang qian qing" }));
	set("title","老地主");
	set("long", "他就是蜀中有名的大地主王千顷。\n");
	set("gender","男性");

	set("age",55);
	set("con",22);
	set("str",23);

	set("combat_exp",200);
	setup();
	carry_object(ARMOR_DIR"cloth")->wear();
}
