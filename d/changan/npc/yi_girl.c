// yi_girl.c

inherit NPC;

void create()
{
	set_name("����Ů��", ({ "girl" }) );
        set("gender", "Ů��" );
	set("age", 12);
	set("long", "һ�����ݵ�СŮ��������������ȴ�������ݡ�\n");
	set("per", 35);
	set("combat_exp", 20000);
	set("attitude", "friendly");

	set_skill("unarmed", 30);
	set_skill("parry", 50);
	set_skill("dodge",100);

	setup();
	add_money("coin", 20);
	carry_object(ARMOR_DIR"cloth")->wear();
}
