// jiaotou.c

inherit NPC;
 
void create()
{
	set_name("��ݽ�ͷ", ({"wuguan jiaotou", "jiaotou"}));
	set("long", "��λ����ݵĽ�ͷ���ڶ��ٵ�����������\n");
	set("gender","����");

	set("age",38);
	set("con",30);
	set("str",20);
	set("max_kee",1000);
	set("max_gin",700);
	set("max_sen",700);
	set("max_force",500);
	set("force",500);
	set("force_factor",10);

	set_skill("dodge",100);
	set_skill("parry",100);
	set_skill("unarmed",90);

	set("combat_exp",70000);

	setup();
	carry_object(ARMOR_DIR"cloth")->wear();
}