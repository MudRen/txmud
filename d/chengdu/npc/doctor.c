// doctor.c

inherit DOCTOR;

void create()
{
	set_name("������", ({"doctor su"}));

	set("title","��ҽ���� ��׹ǡ�");
	set("long", "��������ҽ���ڳɶ�С��������\n");
	set("gender","����");
	set("age",65);
	set("con",20);
	set("str",20);
	set("combat_exp",200);

	setup();
	carry_object(ARMOR_DIR"cloth")->wear();
}
