// doctor.c

inherit DOCTOR;

void create()
{
	set_name("苏理明", ({"doctor su"}));

	set("title","「医死人 肉白骨」");
	set("long", "苏理明的医术在成都小有名气。\n");
	set("gender","男性");
	set("age",65);
	set("con",20);
	set("str",20);
	set("combat_exp",200);

	setup();
	carry_object(ARMOR_DIR"cloth")->wear();
}
