// doctor.c

inherit DOCTOR;

void create()
{
	set_name("胡大夫", ({"doctor hu"}));
	set("long", @TEXT
胡大夫的医术在奉天小有名气。
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
