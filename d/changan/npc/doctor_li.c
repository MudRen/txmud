// doctor_li.c

inherit DOCTOR;

void create()
{
	set_name("李大夫", ({"doctor li","li","doctor"}));
	set("long", @TEXT
他就是京城著名的药店“京东大药房”的
老板，据说也略通医术，人们有一些小病
小灾的都来找他。
TEXT
        );
	set("gender","男性");
	set("age",55);
	set("con",20);
	set("str",20);
	set("combat_exp",200);

	setup();
	carry_object(ARMOR_DIR"cloth")->wear();
}