// genban.c

inherit NPC;

void create()
{
	set_name("����", ({ "servant" }) );
	set("gender", "����" );
	set("age", 28);

	set("long", "����һλһ��ū����ĸ��࣬��������������һ�㹦��\n");

	set("combat_exp", 2500);
	set("per",20);
	set("str", 25);
	set("force", 200);
	set("max_force", 200);
	set("force_factor", 2);
	set_skill("unarmed",20);

	setup();

	carry_object(ARMOR_DIR"cloth")->wear();
}