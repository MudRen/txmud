// doctor.c

inherit DOCTOR;

void create()
{
	set_name("�����", ({"doctor hu"}));
	set("long", @TEXT
������ҽ���ڷ���С��������
TEXT
        );
	set("gender","����");
	set("age",55);
	set("con",20);
	set("str",20);
	set("combat_exp",200);

	setup();
	carry_object(ARMOR_DIR"cloth")->wear();
}
