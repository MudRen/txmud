// dizhu_wang.c

inherit NPC;
 
void create()
{
	set_name("��ǧ��", ({ "wang qian qing" }));
	set("title","�ϵ���");
	set("long", "���������������Ĵ������ǧ�ꡣ\n");
	set("gender","����");

	set("age",55);
	set("con",22);
	set("str",23);

	set("combat_exp",200);
	setup();
	carry_object(ARMOR_DIR"cloth")->wear();
}
