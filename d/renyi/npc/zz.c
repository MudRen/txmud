// zz.c

inherit NPC;

void create()
{
	set_name("������", ({ "liu xia yi" }) );

	set("title", "������ׯ����");

        set("gender", "����" );
        set("age", 56);
        set("long", "����һλ������������ߣ�һ��
��������ŭ������\n");

	set("combat_exp", 5000);

	set("str", 30);

        setup();

	carry_object(__DIR__"obj/cloth")->wear();
}
