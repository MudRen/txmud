// nongfu.c

inherit NPC;

void create()
{
	set_name("ũ��", ({ "nong fu" }) );
	set("gender", "����" );
	set("age", 40 + random(10));
	set("combat_exp", 10000);

	set("long", "����һλ������ڵ�ũ��\n");
	set_skill("unarmed",20);

	setup();

	carry_object(ARMOR_DIR"cloth")->wear();
}
