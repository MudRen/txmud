// smith.c

inherit SMITH;

void create()
{
	set_name("��ͺ��", ({ "liu tu zi" }) );
	set("gender", "����" );
	set("title","����");
	set("age", 48);
	set("str",88);
	set("long", "�����������ϰ塣\n");
	set("combat_exp", 300);
	set("attitude", "friendly");
	set_skill("dodge", 60);
	set_skill("unarmed", 60);

	set_weapon_ability(({"stick", "blade", "whip","staff"}));
	set_ability_level(10);

	setup();

	carry_object(ARMOR_DIR+"cloth")->wear();
}
