// doctor.c

inherit DOCTOR;

void create()
{
	set_name("�Ӽ���", ({ "zhong jishi" }) );

        set("gender", "����" );

        set("age", 38);

	set("long", "�Ӽ����Ǵ�ͬ��Զ����������ҽ��\n");
        set("combat_exp", 2000);
        set("attitude", "friendly");
        set_skill("dodge", 60);
        set_skill("unarmed", 60);
        setup();

	carry_object(ARMOR_DIR+"cloth")->wear();
}