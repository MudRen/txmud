// doctor.c

inherit DOCTOR;

void create()
{
	set_name("������", ({ "li shizhen" }) );
	set("title","�Ȼ����");
        set("gender", "����" );

        set("age", 38);

	set("long", "�������Ǻ��ݳǵ�һλ�����С�\n");
        set("combat_exp", 2000);
        set("attitude", "friendly");
        set_skill("dodge", 60);
        set_skill("unarmed", 60);
        setup();

	carry_object(ARMOR_DIR+"cloth")->wear();
}