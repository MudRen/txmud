// hockboss.c

inherit NPC;

void create()
{
	set_name(" ���в�", ({ "chang youcai" }) );
	set("gender", "����" );
	set("age", 50);

	set("long", "���Ǻ��ݳ��ǵ��̵��ϰ塣\n");

	set("combat_exp", 100);
	set("attitude", "friendly");
	set("max_kee",1000);
	set("max_force",1000);
	set("force_factor",20);

	set_skill("unarmed", 100);
	set_skill("dodge", 100);
	set_skill("sword", 100);
	set_skill("parry", 120);

	setup();
        carry_object(ARMOR_DIR"cloth")->wear();
}
