// gongzi.c

inherit NPC;

void create()
{
	set_name("��������", ({ "gong zi" }) );
	set("gender", "����" );
	set("age", 28);

	set("long", "����һλ�������ε����ṫ�ӣ�������
���Ⱥ�װ�����Ǵ�С�ͽ���������\n");

	set("combat_exp", 1000);
	set("per",35);
	set("str", 20);
	set("force", 200);
	set("max_force", 200);
	set("force_factor", 2);
	setup();

	carry_object(__DIR__"obj/f_fan");
	carry_object(ARMOR_DIR"cloth")->wear();
}