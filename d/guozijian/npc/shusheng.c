// shusheng.c
inherit NPC;

void create()
{
	set_name("����", ({ "student" }) );
	set("long",
		"һ�����׶г��۵�������\n");
	set("age", 25);
	set("attitude", "friendly");
	set("combat_exp", 10);
	set("chat_msg_combat", ({
		"�����е���ɱ���ģ������ģ�\n",
	}) );
	setup();
	carry_object(ARMOR_DIR"cloth")->wear();
	add_money("coin", 20);
}
