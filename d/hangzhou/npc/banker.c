// banker.c

inherit NPC;

void create()
{
	set_name("١����", ({ "tong shouxiang","tong"}) );
	set("title", "Ǯׯ�ƹ�");
	set("gender", "����" );
	set("age", 50);

	set("long",
"١�����Ǻ���Ǯׯ�Ĵ��ƹ񣬰װ����ֵĴ�����
��Զ���ź����΢Ц��\n");

	set("combat_exp", 50000);
	set("attitude", "friendly");

	set_skill("unarmed",100);
	set_skill("parry", 100);
	set_skill("dodge", 100);
	setup();

	carry_object(WEAPON_DIR"sword")->wield();
	carry_object(ARMOR_DIR"cloth")->wear();
}
