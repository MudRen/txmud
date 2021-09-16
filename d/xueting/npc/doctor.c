// doctor_li.c

inherit DOCTOR;

void create()
{
	set_name("李德志", ({"li dezi","li","doctor"}));
	set("long", @TEXT
李德志是雪亭镇药房的老板。雪亭没有专职的医生，
据说他略通医术，人们有一些小病小灾的都来找他。
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