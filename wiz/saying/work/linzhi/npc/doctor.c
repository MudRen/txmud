//doctor.c 藏医

inherit DOCTOR;

void create()
{
    set_name("藏医", ({"zang yi","doctor"}));
	set("long", @TEXT
他就是这里的医生，感觉到你在看他，他冲你怪眼
一翻，吓得你倒退了几步。
TEXT
        );
	set("gender","男性");
	set("age",55);
	set("con",20);
	set("str",20);
	set("combat_exp",200);

	setup();
    carry_object(__DIR__"obj/cloth")->wear();
}
