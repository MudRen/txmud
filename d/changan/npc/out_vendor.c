// out_vendor.c

inherit NPC;

void create()
{
	set_name("�������", ({ "trader" }) );
	set("gender", "����" );
	set("age", 46);
	set("long", "����һλ����ģ�����ˣ���װ���Ͽ��Ǵ�������ġ�\n");
	set("per", 25);
	set("combat_exp", 12000);

	set_skill("unarmed", 30);
	set_skill("parry", 50);
	set_skill("dodge",20);

	setup();
	add_money("coin", 10);
	carry_object(ARMOR_DIR"cloth")->wear();
}
