// doctor_li.c

inherit DOCTOR;

void create()
{
	set_name("���־", ({"li dezi","li","doctor"}));
	set("long", @TEXT
���־��ѩͤ��ҩ�����ϰ塣ѩͤû��רְ��ҽ����
��˵����ͨҽ����������һЩС��С�ֵĶ���������
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