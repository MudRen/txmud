// shusheng.c

inherit NPC;

void create()
{
	set_name("��������", ({ "shu sheng" }) );
	set("gender", "����" );
	set("age", 28);

	set("long", "����һλ�����������\n");

	set("combat_exp", 1000);

	set("chat_chance", 10);
	set("chat_msg", ({
		(: random_move :)
	}) );

	set("per",20);
	set("str", 20);
	set("max_kee",400);
	setup();

	carry_object(ARMOR_DIR"cloth")->wear();
}