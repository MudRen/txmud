
// doctor_hu.c

inherit DOCTOR;

void create()
{
        set_name("����־", ({"hu luanzhi","hu"}));

	set("title","����ҽ");

        set("long", @TEXT
�����ǿ���ҩ�̵��˷�������
���ڻ켣ҩ�̶��꣬Ҳ��ͨ
ҽ����
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
