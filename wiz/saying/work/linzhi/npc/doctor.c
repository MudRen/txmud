//doctor.c ��ҽ

inherit DOCTOR;

void create()
{
    set_name("��ҽ", ({"zang yi","doctor"}));
	set("long", @TEXT
�����������ҽ�����о������ڿ��������������
һ�����ŵ��㵹���˼�����
TEXT
        );
	set("gender","����");
	set("age",55);
	set("con",20);
	set("str",20);
	set("combat_exp",200);

	setup();
    carry_object(__DIR__"obj/cloth")->wear();
}
