// guanjia.c

inherit QUESTER;

void create()
{
	set("class", "tangmen");

	set_name("�ƹܼ�", ({"tang guanjia"}));
	set("title", "�ͷ�����");

	set("long", @TEXT
��������һ�����������ˣ�����΢����
��ȴ�ǳ���ӱ�����ϱ�����߶��Ŀ
����ʮ�꣬�Ը��ֶ����о��мӣ���
���ó��ⶾ��
TEXT
);

	set(NO_KILL, 1);

	set("gender","����");
	set("age",65);
	set("con",20);
	set("str",20);
	set("combat_exp",200);

	setup();
	carry_object(ARMOR_DIR"cloth")->wear();
}
