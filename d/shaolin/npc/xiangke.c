// xiangke.c

inherit NPC;

void create()
{
	set_name("�����", ({ "xiang ke" }) );
	set("gender", "����" );
	set("age", 25+random(15));
	set("long","����һλ��ɽ��ˮ���οͣ�������ϲ
���Ĵ�������\n");
	set("combat_exp", 10000+random(5000));
	set("attitude","peaceful");

	set_skill("dodge",40);
	set_skill("unarmed",40);

	setup();
	carry_object(ARMOR_DIR"cloth")->wear();
}