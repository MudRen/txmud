// yetu.c

inherit NPC;

void create()
{
	set_name("Ұ��", ({ "ye tu" }) );
	set("race", "Ұ��");
	set("age", 3);
	set("max_kee", 700);
	set("long", "һֻ��ɫ��Ұ�����ú��۾������㡣\n");

	set("chat_chance",5);
	set("chat_msg",({
	(: random_move :),
}));
	set("limbs", ({ "ͷ��", "����", "צ��", "β��" }) );
	set("verbs", ({ "bite" }) );

	set("combat_exp", 5000);

	setup();
}
