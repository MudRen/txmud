// smith.c

inherit SMITH;

void create()
{
	set_name("������", ({ "liu er ga" }) );
	set("title","������");

	set("gender", "����" );
	set("age", 38);
	set("str",88);
        set("long", "һ����׳�������ˡ�\n");
        set("combat_exp", 300);
        set("attitude", "friendly");
        set_skill("dodge", 60);
        set_skill("unarmed", 60);
        setup();

	carry_object(ARMOR_DIR+"cloth")->wear();
}
